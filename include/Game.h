//
// Created by Aidan on 10/12/2025.
//

#ifndef INC_220FINALMYVERSION_GAME_H
#define INC_220FINALMYVERSION_GAME_H

#include "Constants.h"
#include "WinServer.h"

class Game {
    friend class WebRequests;
    string gameState = MainMenu;
    WinServer* winServer;
    int* sortArray{};
    int sortArraySize = 10, minVal = -20, maxVal = 20;
    bool running = true;
    bool playing = false;
    void setup();
    void setupPlay();
    void run();
public:
    Game();
    ~Game();
};

#endif //INC_220FINALMYVERSION_GAME_H