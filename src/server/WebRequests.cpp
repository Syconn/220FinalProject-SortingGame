//
// Created by Aidan on 10/12/2025.
//

#include "WebRequests.h"
#include "Constants.h"
#include "Game.h"

int WebRequests::handleRequest(const string &request) {
    data = getBodyValue(request);
    if (request.find("OPTIONS") != string::npos) return OPTIONS;
    if (request.find("GET /page") != string::npos) return PAGE;
    if (request.find("POST /setPage") != string::npos) return SET_PAGE;
    return ERROR;
}

string WebRequests::response(const int code) const {
    if (code == OPTIONS) { // Setup Content Allocation
        return "HTTP/1.1 204 No Content\r\n"
            "Access-Control-Allow-Origin: *\r\n"
            "Access-Control-Allow-Methods: POST, GET, OPTIONS\r\n"
            "Access-Control-Allow-Headers: Content-Type\r\n"
            "\r\n";
    }

    if (code == PAGE) return sendContent("{\"page\": \"" + game->gameState + "\"}");
    if (code == SET_PAGE) {
        if (!data.empty()) {
            game->gameState = data;
            return sendResult(true);
        }
        return sendResult(false);
    }

    // Error route
    return "HTTP/1.1 404 Not Found\r\n"
           "Content-Type: text/plain\r\n"
           "Access-Control-Allow-Origin: *\r\n"
           "\r\n"
           "Route not found.";
}

string WebRequests::sendContent(const string& body) {
    return "HTTP/1.1 200 OK\r\n"
               "Content-Type: application/json\r\n"
               "Access-Control-Allow-Origin: *\r\n"
               "Access-Control-Allow-Methods: POST, GET, OPTIONS\r\n"
               "Access-Control-Allow-Headers: Content-Type\r\n"
               "\r\n" +
               body;
}

string WebRequests::sendResult(const bool success) {
    return "HTTP/1.1 200 OK\r\n"
               "Content-Type: application/json\r\n"
               "Access-Control-Allow-Origin: *\r\n"
               "Access-Control-Allow-Methods: POST, GET, OPTIONS\r\n"
               "Access-Control-Allow-Headers: Content-Type\r\n"
               "\r\n"
               "{\"page\":" + to_string(success) + "}";
}

string getBodyValue(const string& data) {
    if (const auto startIndex = data.find("body"); startIndex != string::npos) {
        auto value = data.substr(startIndex + 7);
        const auto endIndex = value.find("\"");
        return value.substr(0, endIndex);
    }
    return "";
}
