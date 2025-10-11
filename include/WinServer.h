//
// Created by Aidan on 10/9/2025.
//

#ifndef INC_220FINALMYVERSION_WINSERVER_H
#define INC_220FINALMYVERSION_WINSERVER_H

#include <winsock2.h>
#include <string>
#pragma comment(lib, "ws2_32.lib")

using std::string;

class Game;

class WinServer {
    SOCKET serverSocket{};
    sockaddr_in clientAddr{};
    int clientAddrSize{};
    int testCount{};
    int port;
    string respond(int id);
    void start();
    void stop() const;
public:
    explicit WinServer(int port);
    void poll(Game* game);
    ~WinServer();
};


#endif //INC_220FINALMYVERSION_WINSERVER_H