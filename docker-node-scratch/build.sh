#!/usr/bin/env bash

docker build -f ./Dockerfile.build -t retrohacker/nodejs:build .
sudo rm -rf output
docker run --rm -it -v $PWD:/foobar retrohacker/nodejs:build mv output foobar/output
sudo chown retrohacker:retrohacker ./output
docker build -t retrohacker/nodejs-scratch -f Dockerfile.scratch .
echo "built retrohacker/nodejs-scratch"
