# Project: Efficient Data Collection and Uploading to GCP Bucket

## Overview

This project focuses on creating an end-to-end C++ solution that efficiently collects raw data from a downstream module and uploads it to a Google Cloud Platform (GCP) bucket. The key innovation lies in enabling the upstream module to directly access and read this data from the GCP bucket without the need for downloads. This approach enhances efficiency and cost-effectiveness compared to using an Amazon S3 bucket.

## Motivation

Traditional data collection and storage methods often involve intermediate steps, such as downloading data from an S3 bucket before processing it. These steps introduce latency, consume additional resources, and impact overall system performance. By directly accessing data from a GCP bucket, we eliminate unnecessary intermediate steps, resulting in a streamlined and efficient process.

## Features

1. **Data Collection from Downstream Module:**
   - The C++ application collects raw data from a downstream module (logs and Packets).
   - Robust error handling ensures data integrity during collection.

2. **GCP Integration:**
   - Utilizes GCP's native services for data storage.
   - Authenticates securely with GCP using service account credentials.

3. **Efficient Upload to GCP Bucket:**
   - Data is uploaded directly to a GCP bucket without intermediate steps.
   - Parallelized uploads enhance throughput.

4. **Upstream Module Access:**
   - The upstream module can directly read data from the GCP bucket.
   - No need for additional downloads or data transfers.

5. **Cost-Effectiveness:**
   - Reduced data transfer costs due to direct access.
   - Efficient resource utilization.

## Getting Started

1. **Prerequisites:**
   - Install the necessary dependencies (e.g., GCP SDK, C++ compiler).
   - Set up a GCP project and create a bucket.

2. **Configuration:**
   - Configure your GCP credentials (service account key) in the application.
   - Specify the GCP bucket details (e.g., bucket name, region).

3. **Build and Run:**
   - Build the C++ project using your preferred build system (e.g., CMake).
   - Execute the application to start data collection and upload.

## Shell Script

```bash
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
