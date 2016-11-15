FROM ruby

RUN apt-get update \
 && apt-get install -y --force-yes \
      sudo \
 && wget -qO- https://toolbelt.heroku.com/install.sh | sh \
 && rm -rf /var/lib/apt/lists/* \
 && ln -s /usr/local/heroku/bin/heroku /bin/heroku

ENTRYPOINT ["heroku"]
