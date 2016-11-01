#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>

/* Config */
char* ldconfig = "sbin/ldconfig";
char* ldso = "/lib/x86_64-linux-gnu/ld-2.19.so";

void help() {
  printf(""
      "Usage:\n"
      "  bootstrap [dir1 ...] -- command [arg1 ...]\n"
      "\n"
      "  dirN - A list of directories containing libraries to be registered with the dynamic linker\n"
      "  command - (required) The command to be run\n"
      "  argN - A list of arguments to be passed to command\n"
      "\n"
      "Examples:\n"
      "  Load all files in /lib and /usr/lib, and run node passing index.js and ./ as arguments to node:\n"
      "\n"
      "    bootstrap /lib /usr/lib -- node index.js ./\n"
      "\n"
      "  Start a statically linked binary (no need for shared libraries):\n"
      "\n"
      "    bootstrap -- myapp\n"
      "\n");
}

int main(int argc, char** argv) {
  // *_count keep track of which arguments go to which application
  int libdir_count = 0;
  int exec_count = 0;

  // libdir is a boolean that keeps state while we check the arguments
  int libdir = 0;
  // err_msg keeps state while we check the arguments
  char* err_msg = NULL;

  // Used for loop iteration
  int i;

  // Ensure we were passed arguments
  if(argc == 1) err_msg = "Must provide arguments to bootstrap";

  // Get the number of arguments for each argument type so we can allocate
  // arrays for each
  for(i = 1; i < argc; i++) {
    int split = strcmp(argv[i], "--");
    if(split == 0 && libdir == 0) libdir = 1;
    // If we encounter a second "--" string, the user gave us invalid input
    else if(split == 0) {
      err_msg = "Unexpected second --";
      break;
    }
    // Keep track of the number of each type of argument we receive
    else if(libdir == 0) libdir_count++;
    else exec_count++;
  }

  if(exec_count == 0) err_msg = "Must provide command to execute";

  if(err_msg != NULL) {
    printf("%s\n\n", err_msg);
    help();
    return 1;
  }

  // Create an array of all arguments we are going to pass to ldconfig
  char** libdir_argv = malloc(sizeof (char*) * libdir_count);
  for(i = 0; i < libdir_count; i++) {
    libdir_argv[i] = argv[i + 1];
  }

  // Create an array of all arguments going to our application
  char** exec_argv = malloc(sizeof (char*) * exec_count);
  exec_argv[0] = ldso;
  for(i = 0; i < exec_count; i++) {
    exec_argv[i+1] = argv[i + libdir_count + 2];
  }

  // Link all the shared library directories provided by first forking and then
  // replacing the child's execution context with ldconfig
  int status = 0;
  pid_t pid = fork();

  // Make sure the fork succeeded
  if(pid == -1) {
    printf("Failed to fork process to run ldconfig: %s\n", strerror(errno));
    return 1;
  }

  if(pid == 0) {
    // We are the child so execute ldconfig
    execv(ldconfig, libdir_argv);
    return 1;
  } else {
    // We are the parent so wait until the child is done
    waitpid(pid, &status, 0);
  }

  // If linking failed, be sad
  if(status != 0) {
    printf("Failed to link the provided libraries: ");
    for(i = 0; i < libdir_count; i++) {
      printf("%s ", libdir_argv[i]);
    }
    printf("\n");
    return 1;
  }

  // Replace the current run context with ld.so
  execv(ldso, exec_argv);

  // execv only returns if it fails, otherwise the application execution
  // context is replaced with the new process
  printf("Failed to run process: %s\n", strerror(errno));

  return 1;
}
