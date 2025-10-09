//
// Created by Aidan on 10/2/2025.
//

#ifndef INC_220FINALMYVERSION_GAME_H
#define INC_220FINALMYVERSION_GAME_H

#include "Card.h"
#include "Hand.h"
#include "WinServer.h"

using namespace std;

class Game {
    int maxVal = 40, minVal = -40, arraySize{}, cardSize{};
    int *numbers{};
    Card *cards{};
    Hand *hand{};
    WinServer* winServer;
    void setupArray();
    void createHand();
    [[nodiscard]] Card getNextCard() const;
    void play() const;
public:
    explicit Game();
    ~Game();
};


#endif //INC_220FINALMYVERSION_GAME_H