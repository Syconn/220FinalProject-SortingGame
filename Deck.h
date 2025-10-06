//
// Created by Aidan on 10/6/2025.
//

#ifndef INC_220FINALMYVERSION_DECK_H
#define INC_220FINALMYVERSION_DECK_H

#include "Card.h"

class Deck {
    Card *cards;
    int size;
public:
    Deck(Card *cards, int size);
};


#endif //INC_220FINALMYVERSION_DECK_H