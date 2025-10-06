//
// Created by Aidan on 10/6/2025.
//

#ifndef INC_220FINALMYVERSION_DECK_H
#define INC_220FINALMYVERSION_DECK_H

#include "Node.h"

class Deck {
    int size = 30;
    Node* first;
    Node* last;
public:
    explicit Deck(Card cards[]);
    void push(Card* card);
    Card* shift();
    Card* pushAndShift(Card* card);
    void printDeck();
    // ~Deck(); TODO I DON'T Know Needs
};

#endif //INC_220FINALMYVERSION_DECK_H