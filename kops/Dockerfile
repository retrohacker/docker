FROM buildpack-deps:jessie

RUN curl -SsLo /bin/kops https://github.com/kubernetes/kops/releases/download/v1.4.1/kops-linux-amd64 \
 && chmod +x /bin/kops \
 && echo "Downloading kubectl..." \
 && curl -SsL https://storage.googleapis.com/kubernetes-release/release/v1.2.7/kubernetes-client-linux-amd64.tar.gz \
  | tar -xzv --strip-components=3 \
 && mv /kubectl /bin/kubectl

WORKDIR /usr/src/app

ENTRYPOINT ["kops"]
