//
// Created by Aidan on 10/6/2025.
//

#ifndef INC_220FINALMYVERSION_NODE_H
#define INC_220FINALMYVERSION_NODE_H

#include "Card.h"
#include <iostream>

class Node {
    friend class DLL;
    Card *card;
    Node* prev;
    Node* next;
public:
    Node(): card(nullptr), prev(nullptr), next(nullptr) {}
    explicit Node(Card *card): card(card), prev(nullptr), next(nullptr) {}
    void printNode() const;
    ~Node();
};


#endif //INC_220FINALMYVERSION_NODE_H