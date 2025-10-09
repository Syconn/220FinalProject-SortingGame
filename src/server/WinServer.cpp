//
// Created by Aidan on 10/9/2025.
//

#include "WinServer.h"
#include <iostream>

WinServer::WinServer(const int port) {
    this->port = port;
    start();
    run();
}

string WinServer::handleRequest(const string& request) {
    // Handle POST /click
    if (request.find("POST /click") != string::npos) {
        testCount++;
        const string body = "{\"count\": " + std::to_string(testCount) + "}";
        return "HTTP/1.1 200 OK\r\n"
               "Content-Type: application/json\r\n"
               "Access-Control-Allow-Origin: *\r\n"
               "Access-Control-Allow-Methods: POST, GET, OPTIONS\r\n"
               "Access-Control-Allow-Headers: Content-Type\r\n"
               "\r\n" +
               body;
    }

    // Handle GET /count (for optional refresh)
    if (request.find("GET /count") != string::npos) {
        const string body = "{\"count\": " + std::to_string(testCount) + "}";
        return "HTTP/1.1 200 OK\r\n"
               "Content-Type: application/json\r\n"
               "Access-Control-Allow-Origin: *\r\n"
               "\r\n" +
               body;
    }

    // Handle OPTIONS (CORS preflight)
    if (request.find("OPTIONS") != string::npos) {
        return "HTTP/1.1 204 No Content\r\n"
               "Access-Control-Allow-Origin: *\r\n"
               "Access-Control-Allow-Methods: POST, GET, OPTIONS\r\n"
               "Access-Control-Allow-Headers: Content-Type\r\n"
               "\r\n";
    }

    // Default route
    return "HTTP/1.1 404 Not Found\r\n"
           "Content-Type: text/plain\r\n"
           "Access-Control-Allow-Origin: *\r\n"
           "\r\n"
           "Route not found.";
}

void WinServer::start() {
    WSADATA wsaData;
    sockaddr_in serverAddr{};
    clientAddrSize = sizeof(clientAddr);

    WSAStartup(MAKEWORD(2, 2), &wsaData);

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(port);

    if (const int error = bind(serverSocket, reinterpret_cast<sockaddr *>(&serverAddr), sizeof(serverAddr)); error != 0) std::cout << "Issue Binding Port" << std::endl;
    listen(serverSocket, 5);
    std::cout << "Server running on http://localhost:" << port << std::endl;
}

void WinServer::stop() const {
    closesocket(serverSocket);
    WSACleanup();
}

void WinServer::run() {
    while (true) {
        const SOCKET clientSocket = accept(serverSocket, reinterpret_cast<sockaddr *>(&clientAddr), &clientAddrSize);
        if (clientSocket == INVALID_SOCKET) continue;

        char buffer[2048];
        int bytesReceived = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
        if (bytesReceived > 0) {
            buffer[bytesReceived] = '\0';
            std::string request(buffer);

            std::cout << "Received request:\n" << request << std::endl;

            std::string response = handleRequest(request);
            send(clientSocket, response.c_str(), response.size(), 0);
        }
        closesocket(clientSocket);
    }
}

WinServer::~WinServer() {
    stop();
}
