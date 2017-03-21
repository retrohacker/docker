# Get CWD

CWD=${PWD}

# Get Script Directory: resolve $SOURCE until the file is no longer a symlink
SOURCE="$1"
while [ -h "${SOURCE}" ]; do
  DIR="$( cd -P "$( dirname "$SOURCE" )" && pwd )"
  SOURCE="$(readlink "$SOURCE")"
  [[ $SOURCE != /* ]] && SOURCE="$DIR/$SOURCE"
done
DIR="$( cd -P "$( dirname "$SOURCE" )" && pwd )"

cd "${DIR}"

# Image name is the name of the directory
IMAGE_NAME="$(basename ${DIR})"

# By default, only rebuild if the Dockerfile changes
if [ -z "${CACHE_FILES}" ]; then
  CACHE_FILES="Dockerfile"
fi

# Check to see if the Dockerfile needs to be built
BUILD_CACHE=".rebuild"
if diff "${BUILD_CACHE}" <(ls -alh ${CACHE_FILES} | tee "${BUILD_CACHE}") 1>/dev/null 2>/dev/null; then
  :
else
  echo "Building ${IMAGE_NAME} from ${DIR}"
  docker build -t "${IMAGE_NAME}" . || {
    rm "${BUILD_CACHE}";
    exit 1;
  }
fi
