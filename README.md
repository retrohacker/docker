My Dockerfiles
==============

Why does this repo exist? I'm moving a majority of my day-to-day into Docker. This results in a _lot_ of Dockerfiles. I don't want to risk losing everything so I need an SCM. I also don't want to maintain 20 gazillion GitHub repos, so I'm condensening everything down here. You may find some stuff here that is useful, but documentation will be sparse. Best bet is to just DM me on twitter if you want to try using anything here @retrohack3r.

# Creating a new app

```
cp -r ./template ./[app_name]
cd ./[app_name]
# Make necessary changes to ./Dockerfile and ./cmd
./install.sh
git add ./
```
