# Check http://releases.llvm.org/download.html#8.0.0 for the latest available binaries
FROM ubuntu:18.04

# Make sure the image is updated, install some prerequisites,
# Download the latest version of Clang (official binary) for Ubuntu
# Extract the archive and add Clang to the PATH
RUN apt-get update && apt-get install -y \
  xz-utils \
  build-essential \
  libboost-all-dev \
  vim \
  cmake

RUN apt-get update && apt-get install -y cmake

WORKDIR app
COPY . .
COPY src src
COPY include include


RUN cmake .
RUN make
RUN /bin/sh