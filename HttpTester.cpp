#include "httplib.h"
#include <iostream>

int main()
{
    std::cout << "HTTP TESTER\n";

    httplib::Client client("http://api.sparselab.com");
    auto response = client.Get("/api/Report");
    std::cout << "Error:" << response.error() << std::endl;
    std::cout << "Status: " << response->status << std::endl;
    std::cout << "Body: " << response->body << std::endl;
}
