#include <iostream>
#include <memory>
#include <string>
#include <grpcpp/grpcpp.h>
#include "data_payload_service.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using DRED::DataPayload;
using DRED::StatusResponse;
using DRED::DataPayloadService;

class DataPayloadServiceImpl final : public DataPayloadService::Service {
    Status SendDataPayload(ServerContext* context, const DataPayload* request, StatusResponse* response) override {
        // Implement your logic to process the data payload
        std::cout << "Received payload with center frequency: " << request->center_frequency() << std::endl;

        // Respond with success
        response->set_success(true);
        response->set_message("Payload processed successfully");
        return Status::OK;
    }
};

void RunServer() {
    std::string server_address("0.0.0.0:50051");
    DataPayloadServiceImpl service;

    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;
    server->Wait();
}

int main(int argc, char** argv) {
    RunServer();
    return 0;
}