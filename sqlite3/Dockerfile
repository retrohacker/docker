FROM debian:jessie

RUN apt-get update \
 && apt-get install -y \
      sqlite3

WORKDIR /usr/src/app
ENTRYPOINT ["sqlite3"]
CMD ["--help"]
