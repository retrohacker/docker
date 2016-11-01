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

ENV ANSIBLE_ROLES_PATH /usr/src/ansible/roles

WORKDIR /usr/src/app

ENTRYPOINT ["ansible"]
