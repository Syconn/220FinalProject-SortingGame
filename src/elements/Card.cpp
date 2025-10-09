//
// Created by Aidan on 10/6/2025.
//

#include "Card.h"

string Card::details() {
    return name;
}

void Card::sortArray(int arr[], const int size) const {
    func(arr, size);
}

