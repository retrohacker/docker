FROM node:6

RUN apt-get update \
 && apt-get install -y \
      xvfb \
      iceweasel \
 && rm -rf /var/lib/apt/lists/*

ENV LC_ALL="en.utf-8"
