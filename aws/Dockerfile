FROM python

RUN apt-get update \
 && apt-get install -y --force-yes --no-install-recommends\
    groff \
 && rm -rf /var/lib/apt/lists/*;

RUN pip install awscli

WORKDIR /usr/src/app

ENTRYPOINT ["aws"]

CMD ["help"]
