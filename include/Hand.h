//
// Created by Aidan on 10/6/2025.
//

#ifndef INC_220FINALMYVERSION_HAND_H
#define INC_220FINALMYVERSION_HAND_H

#include "Card.h"
#include "Deck.h"
#include "Node.h"

class Hand {
    friend class Deck;
    int size = 4;
    Card* cards[];
public:
    Hand();
    void use(int index);
    void printHand();
};


#endif //INC_220FINALMYVERSION_HAND_H