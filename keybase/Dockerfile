FROM buildpack-deps:jessie-curl

RUN curl -O https://prerelease.keybase.io/keybase_amd64.deb \
 && apt-get update \
 && apt-get install -y \
      libappindicator1 \
      fuse \
 && dpkg -i keybase_amd64.deb \
 && apt-get install -f \
 && rm keybase_amd64.deb

RUN useradd keybase

USER keybase

ENTRYPOINT ["/bin/bash"]
