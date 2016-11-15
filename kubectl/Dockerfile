FROM buildpack-deps:jessie

RUN curl -SsL https://storage.googleapis.com/kubernetes-release/release/v1.2.7/kubernetes-client-linux-amd64.tar.gz \
  | tar -xzv --strip-components=3 \
 && mv /kubectl /bin/kubectl

WORKDIR /usr/src/app

ENTRYPOINT ["kubectl"]
