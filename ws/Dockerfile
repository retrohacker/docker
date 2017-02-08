FROM node:6

RUN wget -O /usr/local/bin/dumb-init https://github.com/Yelp/dumb-init/releases/download/v1.2.0/dumb-init_1.2.0_amd64 \
 && chmod +x /usr/local/bin/dumb-init

RUN npm install -g local-web-server

WORKDIR /usr/src/data

ENTRYPOINT ["dumb-init", "--", "ws"]
