FROM python:2.7

RUN apt-get update \
 && apt-get install -y --force-yes --no-install-recommends\
      vim \
      curl \
      wget \
      less \
 && rm -rf /var/lib/apt/lists/*;

RUN wget -O /usr/local/bin/dumb-init https://github.com/Yelp/dumb-init/releases/download/v1.2.0/dumb-init_1.2.0_amd64 \
 && chmod +x /usr/local/bin/dumb-init

ENV VERSION 148.0.1

RUN echo "${VERSION}"

RUN curl https://dl.google.com/dl/cloudsdk/channels/rapid/downloads/google-cloud-sdk-${VERSION}-linux-x86_64.tar.gz | tar xvz

RUN /google-cloud-sdk/install.sh
RUN /google-cloud-sdk/bin/gcloud components install kubectl
ENV PATH $PATH:/google-cloud-sdk/bin
ENV KUBECONFIG /root/.config/kube/config
ENV EDITOR=vim

ENTRYPOINT ["dumb-init", "--", "gcloud"]
