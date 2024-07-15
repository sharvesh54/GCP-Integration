#include "gcp1.h"

namespace gcs = google::cloud::storage;

void Upload(const std::string& file_name, const std::string& bucket_name, const std::string& object_name) {
    gcs::Client client; 

    google::cloud::StatusOr<gcs::ObjectMetadata> metadata = client.UploadFile(file_name, bucket_name, object_name, gcs::IfGenerationMatch(0));

    //auto metadata = client.UploadFile(file_name, bucket_name, object_name, gcs::IfGenerationMatch(0));

    if (!metadata) {
        std::cerr << "Error uploading file: " << metadata.status().message()
            << std::endl;
        return;
    }

    std::cout << "Uploaded " << file_name << " to object "
        << metadata->name() << " in bucket " << metadata->bucket()
        << std::endl;
}

void Readxyz(const std::string& bucket_name, const std::string& object_name, std::size_t start, std::size_t end) {
    gcs::Client client;

    gcs::ObjectReadStream stream = client.ReadObject(bucket_name, object_name, gcs::ReadRange(start, end));

    //auto stream = client.ReadObject(bucket_name, object_name, gcs::ReadRange(start, end));

    std::string contents{std::istreambuf_iterator<char>{stream}, {}};

    std::cout << "Contents at position " << start << ":\n" << contents << "\n";
}

int main() {
    std::string local_file = "file-path"; 
    std::string bucket_name = "bucket-name"; 
    std::string object_name = "destination/object.txt"; 
    std::size_t start_position = 100;
    std::size_t end_position = 400;

    Upload(local_file, bucket_name, object_name);
    Readxyz(bucket_name, object_name, start_position, end_position);

    return 0;
}