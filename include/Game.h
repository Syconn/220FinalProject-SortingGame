//
// Created by Aidan on 10/2/2025.
//

#ifndef INC_220FINALMYVERSION_GAME_H
#define INC_220FINALMYVERSION_GAME_H

#include "Card.h"
#include "Hand.h"
#include "WinServer.h"
#include "GameState.h"

using namespace std;

class Game {
    int maxVal = 40, minVal = -40, arraySize = 10, cardSize = 6;
    int *numbers{};
    Card *cards{};
    Hand *hand{};
    WinServer* winServer{};
    GameState state = GameState::MainMenu;
    bool playing = false, running = true;
    // bool gameOver{};
    void setupArray();
    void createHand();
    bool turn() const;
    void run() const;
    [[nodiscard]] Card getNextCard() const;
public:
    explicit Game();
    ~Game();
};


#endif //INC_220FINALMYVERSION_GAME_H