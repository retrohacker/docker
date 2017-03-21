#!/usr/bin/env bash

set -x
SOURCE="${BASH_SOURCE[0]}"
while [ -h "${SOURCE}" ]; do
  DIR="$( cd -P "$( dirname "$SOURCE" )" && pwd )"
  SOURCE="$(readlink "$SOURCE")"
  [[ $SOURCE != /* ]] && SOURCE="$DIR/$SOURCE"
done
DIR="$( cd -P "$( dirname "$SOURCE" )" && pwd )"
cd "${DIR}"
IMAGE_NAME="$(basename ${DIR})"
mv cmd "${IMAGE_NAME}"
cd ../.bin
ln -s "${DIR}/${IMAGE_NAME}" .
echo "!$(basename ${DIR})/${IMAGE_NAME}" >> ../.gitignore
rm "${DIR}/install.sh"
