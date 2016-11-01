FROM buildpack-deps:jessie

RUN curl -SsLo terraform.zip http://releases.hashicorp.com/terraform/0.7.7/terraform_0.7.7_linux_amd64.zip \
 && apt-get update \
 && apt-get install -y --force-yes --no-install-recommends \
      unzip \
 && rm -rf /var/lib/apt/lists/* \
 && unzip terraform.zip \
 && rm terraform.zip \
 && mv terraform /bin/terraform

WORKDIR /usr/src/app

ENTRYPOINT ["terraform"]
