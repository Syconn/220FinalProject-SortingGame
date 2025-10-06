//
// Created by Aidan on 10/2/2025.
//

#ifndef INC_220FINALMYVERSION_GAME_H
#define INC_220FINALMYVERSION_GAME_H

#include "../include/SortUtil.h"
#include "../include/ArrayUtil.h"
#include "../include/Card.h"
#include <iostream>

using namespace std;

class Game {
    int maxVal = 40, minVal = -40, arraySize, cardSize;
    int *numbers;
    Card *cards;
    void setupArrayLength();
    void generateArrayNumbers();
    void createCards();
    void play() const;
    void test() const;

    static int selectAlgorithm(const string options[], int size); // TODO TEMP
public:
    Game(bool playGame);
};


#endif //INC_220FINALMYVERSION_GAME_H