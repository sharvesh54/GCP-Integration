#pragma once

#include <iostream>
#include <google/cloud/storage/client.h>

void Upload(const std::string& file_name, const std::string& bucket_name, const std::string& object_name);          //upload file
void Readxyz(const std::string& bucket_name, const std::string& object_name, std::size_t start, std::size_t end);      //Read the file 