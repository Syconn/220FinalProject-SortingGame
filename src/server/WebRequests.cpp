//
// Created by Aidan on 10/12/2025.
//

#include "WebRequests.h"
#include "Constants.h"

int handleRequest(const string &request) {
    if (request.find("OPTIONS") != string::npos) return OPTIONS;
    return ERROR;
}

string response(const int code) {
    // Handle POST /click
    // if (request.find("POST /click") != string::npos) {
    //     testCount++;
    //     const string body = "{\"count\": " + std::to_string(testCount) + "}";
    //     return "HTTP/1.1 200 OK\r\n"
    //            "Content-Type: application/json\r\n"
    //            "Access-Control-Allow-Origin: *\r\n"
    //            "Access-Control-Allow-Methods: POST, GET, OPTIONS\r\n"
    //            "Access-Control-Allow-Headers: Content-Type\r\n"
    //            "\r\n" +
    //            body;
    // }

    // Handle GET /count (for optional refresh)
    // if (request.find("GET /count") != string::npos) {
    //     const string body = "{\"count\": " + std::to_string(testCount) + "}";
    //     return "HTTP/1.1 200 OK\r\n"
    //            "Content-Type: application/json\r\n"
    //            "Access-Control-Allow-Origin: *\r\n"
    //            "\r\n" +
    //            body;
    // }

    // Handle OPTIONS (CORS preflight)
    // if (request.find("OPTIONS") != string::npos) {
    //     return "HTTP/1.1 204 No Content\r\n"
    //            "Access-Control-Allow-Origin: *\r\n"
    //            "Access-Control-Allow-Methods: POST, GET, OPTIONS\r\n"
    //            "Access-Control-Allow-Headers: Content-Type\r\n"
    //            "\r\n";
    // }

    if (code == OPTIONS) {
        std::cout << "OPTIONS" << std::endl;
    }

    // Default route
    return "HTTP/1.1 404 Not Found\r\n"
           "Content-Type: text/plain\r\n"
           "Access-Control-Allow-Origin: *\r\n"
           "\r\n"
           "Route not found.";
}