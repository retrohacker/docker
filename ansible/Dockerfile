FROM ubuntu:xenial

RUN apt-get update \
 && apt-get install -y --force-yes --no-install-recommends\
      software-properties-common \
 && apt-add-repository ppa:ansible/ansible \
 && apt-get update \
 && apt-get install -y --force-yes \
      ansible \
      git \
 && rm -rf /var/lib/apt/lists/*;

RUN apt-get update \
 && apt-get install -y --force-yes --no-install-recommends\
    groff \
    python-dev \
    build-essential \
    python-pip \
 && rm -rf /var/lib/apt/lists/* \
 && pip install --upgrade pip \
 && pip install --upgrade virtualenv

RUN pip install awscli

ENV ANSIBLE_ROLES_PATH /usr/src/ansible/roles

WORKDIR /usr/src/app

ENTRYPOINT ["ansible"]
