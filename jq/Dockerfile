FROM debian:jessie

RUN apt-get update \
 && apt-get install -y --force-yes --no-install-recommends\
      jq \
 && rm -rf /var/lib/apt/lists/*;

ENTRYPOINT ["jq"]
