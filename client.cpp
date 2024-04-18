#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>
#include "data_payload_service.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using DRED::DataPayload;
using DRED::StatusResponse;
using DRED::DataPayloadService;

class DataPayloadClient {
public:
    DataPayloadClient(std::shared_ptr<Channel> channel)
        : stub_(DataPayloadService::NewStub(channel)) {}

    // Assembles the client's payload, sends it and prints the response back from the server.
    void SendDataPayload(const std::string& payload, double center_frequency, uint64_t start_time, float transmit_angle) {
        DataPayload request;
        request.set_payload(payload);
        request.set_center_frequency(center_frequency);
        request.set_start_time(start_time);
        request.set_transmit_angle(transmit_angle);

        StatusResponse response;
        ClientContext context;

        Status status = stub_->SendDataPayload(&context, request, &response);

        if (status.ok()) {
            std::cout << "Server response: " << response.message() << std::endl;
        } else {
            std::cout << "RPC failed" << std::endl;#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>
#include "data_payload_service.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using DRED::DataPayload;
using DRED::StatusResponse;
using DRED::DataPayloadService;

class DataPayloadClient {
public:
    DataPayloadClient(std::shared_ptr<Channel> channel)
        : stub_(DataPayloadService::NewStub(channel)) {}

    // Assembles the client's payload, sends it and prints the response back from the server.
    void SendDataPayload(const std::string& payload, double center_frequency, uint64_t start_time, float transmit_angle) {
        DataPayload request;
        request.set_payload(payload);
        request.set_center_frequency(center_frequency);
        request.set_start_time(start_time);
        request.set_transmit_angle(transmit_angle);

        StatusResponse response;
        ClientContext context;

        Status status = stub_->SendDataPayload(&context, request, &response);

        if (status.ok()) {
            std::cout << "Server response: " << response.message() << std::endl;
        } else {
            std::cout << "RPC failed" << std::endl;
        }
    }

private:
    std::unique_ptr<DataPayloadService::Stub> stub_;
};

int main(int argc, char** argv) {
    DataPayloadClient client(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
    std::string payload = "example_payload";
    client.SendDataPayload(payload, 2.4, 123456789, 45.0);
    return 0;
}
        }
    }

private:
    std::unique_ptr<DataPayloadService::Stub> stub_;
};

int main(int argc, char** argv) {
    DataPayloadClient client(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
    std::string payload = "example_payload";
    client.SendDataPayload(payload, 2.4, 123456789, 45.0);
    return 0;
}
