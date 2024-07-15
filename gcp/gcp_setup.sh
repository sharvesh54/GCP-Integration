#!/bin/bash

yum install cmake git -y
git clone https://github.com/microsoft/vcpkg.git
./bootstrap-vcpkg.sh
export VCPKG_ROOT=/path/to/vcpkg
export PATH=$VCPKG_ROOT:$PATH
vcpkg new --application

# commands to install and configure Google cloud SDK
mkdir build
cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build .
curl -O https://dl.google.com/dl/cloudsdk/channels/rapid/downloads/google-cloud-cli-477.0.0-linux-x86_64.tar.gz
tar -xf google-cloud-cli-477.0.0-linux-x86_64.tar.gz
./google-cloud-sdk/install.sh
./google-cloud-sdk/bin/gcloud init


gcloud auth application-default login
gcloud auth activate-service-account --key-file="/root/gcp-nw-integration-e34a707028ff.json"
export GOOGLE_APPLICATION_CREDENTIALS=/root/gcp-nw-integration-e34a707028ff.json

#Run the executable
cd gcp/build
./gcp
