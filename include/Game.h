//
// Created by Aidan on 10/2/2025.
//

#ifndef INC_220FINALMYVERSION_GAME_H
#define INC_220FINALMYVERSION_GAME_H

#include "Card.h"
#include "SortUtil.h"
#include "ArrayUtil.h"
#include <iostream>
#include "Hand.h"

using namespace std;

class Game {
    int maxVal = 40, minVal = -40, arraySize, cardSize;
    int *numbers;
    Card *cards;
    Hand *hand;
    void setupArray();
    void createHand();
    Card getNextCard() const;
    void play() const;
public:
    explicit Game();
    ~Game();
};


#endif //INC_220FINALMYVERSION_GAME_H