//
// Created by Aidan on 10/9/2025.
//

#ifndef INC_220FINALMYVERSION_WINSERVER_H
#define INC_220FINALMYVERSION_WINSERVER_H

#include <winsock2.h>
#include <string>
#pragma comment(lib, "ws2_32.lib")

using std::string;

class WinServer {
    SOCKET serverSocket{};
    sockaddr_in clientAddr{};
    int clientAddrSize{};
    int testCount{};
    int port;
    void start();
    void stop() const;
    void run();
    string handleRequest(const string& request);
public:
    WinServer(int port);
    ~WinServer();
};


#endif //INC_220FINALMYVERSION_WINSERVER_H