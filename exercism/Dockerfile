FROM buildpack-deps:jessie-curl

RUN cd /bin \
 && curl -sLq https://github.com/exercism/cli/releases/download/v2.3.0/exercism-linux-64bit.tgz | \
     tar -xzv \
 && chmod +x /bin/exercism

WORKDIR /usr/src/app

ENTRYPOINT ["exercism"]
CMD ["--help"]
