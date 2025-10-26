#include "httplib.h"
#include <iostream>

int main() {
    httplib::Server svr;

    svr.Get("/health", [](const httplib::Request&, httplib::Response& res) {
        res.set_content("{\"status\":\"ok\"}", "application/json");
    });

    svr.Get("/sum", [](const httplib::Request& req, httplib::Response& res) {
        auto a = req.get_param_value("a");
        auto b = req.get_param_value("b");
        int x = std::stoi(a);
        int y = std::stoi(b);
        int s = x + y;
        res.set_content("{\"sum\":" + std::to_string(s) + "}", "application/json");
    });

    std::cout << "Server running on 0.0.0.0:8080\n";
    svr.listen("0.0.0.0", 8080);
}
