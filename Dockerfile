FROM ubuntu:impish-20211015

VOLUME /home/admin/Desktop/projects
WORKDIR /home/admin/Desktop/projects

RUN apt-get update && apt-get install -y git gcc gcc-multilib xorriso make nasm mtools g++ curl gzip bzip2 g++-multilib ca-certificates ninja-build --no-install-recommends
