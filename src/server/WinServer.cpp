//
// Created by Aidan on 10/9/2025.
//

#include "WinServer.h"
#include "Game.h"
#include <iostream>

WinServer::WinServer(const int port) {
    this->port = port;
    start();
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

void WinServer::poll(Game* game) {
    const SOCKET clientSocket = accept(serverSocket, reinterpret_cast<sockaddr *>(&clientAddr), &clientAddrSize);
    if (clientSocket == INVALID_SOCKET) return;

    char buffer[2048];
    if (const int bytesReceived = recv(clientSocket, buffer, sizeof(buffer) - 1, 0); bytesReceived > 0) {
        buffer[bytesReceived] = '\0';
        const string request(buffer);
        const int response = handleRequest(request);
        const string res = respond(response);
        send(clientSocket, res.c_str(), res.size(), 0);
    }
    closesocket(clientSocket);
}

string WinServer::respond(int id) {
    return "HTTP/1.1 404 Not Found\r\n"
           "Content-Type: text/plain\r\n"
           "Access-Control-Allow-Origin: *\r\n"
           "\r\n"
           "Route not found.";
}


WinServer::~WinServer() {
    stop();
}
