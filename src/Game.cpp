//
// Created by Aidan on 10/2/2025.
//

#include "Game.h"

Game::Game() {
    srand(time(nullptr));
    setupArray();
    createHand();
    play();
}

void Game::setupArray() {
    std::cout << "How long do you want the array to be?" << std::endl;
    string selectionStr;
    getline(cin, selectionStr);
    arraySize = stoi(selectionStr);
    numbers = new int[arraySize];
    for (int i = 0; i < arraySize; i++) numbers[i] = rand() % (maxVal - minVal + 1) + minVal;
}

void Game::createHand() {
    cardSize = 6;
    cards = new Card[cardSize]; // Creates all the possible cards
    cards[0] = Card("Selection Sort", "", selectionSort);
    cards[1] = Card("Bubble Sort", "", bubbleSort);
    cards[2] = Card("Insert Sort", "", insertionSort);
    cards[3] = Card("Quick Sort", "", quickSort);
    cards[4] = Card("Merge Sort", "", mergeSort);
    cards[5] = Card("bucket Sort", "", bucketSort);
    hand = new Hand([this] { return getNextCard(); });
}

Card Game::getNextCard() const {
    return cards[rand() % cardSize];
}

void Game::play() const {
    while (!isSorted(numbers, arraySize)) {
        printArray(numbers, arraySize);
        hand->pickCard(numbers, arraySize);
    }
    printArray(numbers, arraySize);
    cout << "Congrats Your Sorted the Array" << endl;
}

Game::~Game() {
    delete hand;
    delete[] numbers;
    delete[] cards;
}

