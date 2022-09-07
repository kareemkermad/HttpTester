#include "httplib.h"
#include <iostream>

int main()
{
    std::cout << "HTTP TESTER\n";

    std::cout << "TEST GET:" << std::endl;

    httplib::Client client("http://api.sparselab.com");
    auto response = client.Get("/api/Report");
    std::cout << "Error:" << response.error() << std::endl;
    std::cout << "Status: " << response->status << std::endl;
    std::cout << "Body: " << response->body << std::endl;

    std::cout << "TEST POST:" << std::endl;

    std::string json = "{\"RequestId\":\"900ea9c2-87ff-4072-8b8d-3952a367be2f\",\"Event\":\"Finished\",\"PeakMemoryConsumption\":19,\"TotalRunningTime\":0,\"SecretKey\":\"^ZQr26#i$eiSh@%ik9r20ztYLRb^3C@J\"}";
    response = client.Post("/api/RequestTelemetry", json, "application/json");
    std::cout << "Error:" << response.error() << std::endl;
    std::cout << "Status: " << response->status << std::endl;
    std::cout << "Body: " << response->body << std::endl;
}
