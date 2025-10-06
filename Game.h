//
// Created by Aidan on 10/2/2025.
//

#ifndef INC_220FINALMYVERSION_GAME_H
#define INC_220FINALMYVERSION_GAME_H

#include "Sorter.h"
#include "ArrayUtil.h"
#include <iostream>

using namespace std;

class Game {
    int maxVal = 40, minVal = -40, arraySize;
    int *numbers;
    void setupArrayLength();
    void generateArrayNumbers();
    void play();

    static int selectAlgorithm(const string options[], int size); // TODO TEMP
public:
    Game();
};


#endif //INC_220FINALMYVERSION_GAME_H