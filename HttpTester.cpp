#include "httplib.h"
#include <iostream>
#include <chrono>
#include <thread>
int main(int argc, char* argv[])
{
    std::cout << "HTTP TESTER\n";

    const long long time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    const std::string json = "{\"Timestamp\":" + std::to_string(time) + "}";
    
    httplib::Client client("http://api.sparselab.com");
    auto response = client.Post("/api/StartupTimer", json, "application/json");
    while (response.error() != httplib::Error::Success)
    {
        std::cout << "Error:" << response.error() << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        response = client.Post("/api/StartupTimer", json, "application/json");
    }
    
    std::cout << "Status: " << response->status << std::endl;
    std::cout << "Body: " << response->body << std::endl;
}
