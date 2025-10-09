//
// Created by Aidan on 10/6/2025.
//

#ifndef INC_220FINALMYVERSION_HAND_H
#define INC_220FINALMYVERSION_HAND_H

#include "Card.h"

class Hand {
    static constexpr int size = 4;
    function<Card()> nextCard;
    Card cards[size];
    void printHand();
public:
    explicit Hand(const function<Card()> &nextCard);
    void pickCard(int arr[], int arraySize);
};


#endif //INC_220FINALMYVERSION_HAND_H