//
// Created by Aidan on 10/6/2025.
//

#include "Hand.h"

Hand::Hand(const function<Card()> &nextCard) {
    this->nextCard = nextCard;
    for (int i = 0; i < size; i++) {
        cards[i] = nextCard();
    }
}

void Hand::pickCard(int arr[], const int arraySize) {
    string selectionStr;
    std::cout << "Your Hand: ";
    printHand();
    std::cout << "Pick a Car (1-" << size + 1 << ')' << std::endl;
    getline(std::cin, selectionStr);
    if (const int select = stoi(selectionStr) - 1; select < size && select >= 0) {
        std::cout << "You selected " << cards[select].details() << std::endl;
        cards[select].sortArray(arr, arraySize);
        cards[select] = nextCard();
    } else std::cout << "You selected an invalid selection" << std::endl;
}

void Hand::printHand() {
    for (int i = 0; i < size; i++) std::cout << i + 1 << " " << cards[i].details() << " ";
    std::cout << std::endl;
}

