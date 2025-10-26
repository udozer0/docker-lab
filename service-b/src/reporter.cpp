#include "httplib.h"
#include <iostream>
#include <cstdlib>

int main() {
    const char* host = std::getenv("API_HOST");
    if (!host) host = "api";
    int port = 8080;

    httplib::Client cli(host, port);

    if (auto res = cli.Get("/health")) {
        std::cout << "Health: " << res->body << std::endl;
    } else {
        std::cerr << "Failed to reach API\n";
        return 1;
    }

    if (auto res = cli.Get("/sum?a=5&b=7")) {
        std::cout << "Sum: " << res->body << std::endl;
    } else {
        std::cerr << "Failed to get sum\n";
        return 1;
    }

    return 0;
}
