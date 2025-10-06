//
// Created by Aidan on 10/6/2025.
//

#include "Node.h"

void Node::printNode() const {
    std::cout << card->details() << std::endl;
}

Node::~Node() {
    if (card != nullptr) {
        std::cout << "Deleting " << card->details();
        delete card;
    }
}
