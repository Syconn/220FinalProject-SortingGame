//
// Created by Aidan on 10/2/2025.
//

#include "Game.h"
#include "ArrayUtil.h"
#include "SortUtil.h"

Game::Game() {
    srand(time(nullptr));
    winServer = new WinServer(8080);
    setupArray();
    createHand();
    run();
}

void Game::setupArray() {
    // std::cout << "How long do you want the array to be?" << std::endl; TODO CUSTOMIZATION CODE
    // string selectionStr;
    // getline(cin, selectionStr); # stoi(selectionStr)
    numbers = new int[arraySize];
    for (int i = 0; i < arraySize; i++) numbers[i] = rand() % (maxVal - minVal + 1) + minVal;
}

void Game::createHand() {
    cards = new Card[cardSize];
    cards[0] = Card("Selection Sort", "", selectionSort);
    cards[1] = Card("Bubble Sort", "", bubbleSort);
    cards[2] = Card("Insert Sort", "", insertionSort);
    cards[3] = Card("Quick Sort", "", quickSort);
    cards[4] = Card("Merge Sort", "", mergeSort);
    cards[5] = Card("Bucket Sort", "", bucketSort);
    hand = new Hand([this] { return getNextCard(); });
}

Card Game::getNextCard() const {
    return cards[rand() % cardSize];
}

bool Game::turn() const {
    if (isSorted(numbers, arraySize)) {
        printArray(numbers, arraySize);
        cout << "Congrats Your Sorted the Array" << endl;
        return true;
    }
    printArray(numbers, arraySize);
    hand->pickCard(numbers, arraySize);
    return false;
}

void Game::run() const {
    while (running) {
        if (!playing) {
            winServer->poll(this);
        }
    }
}

Game::~Game() {
    delete hand;
    delete[] numbers;
    delete[] cards;
}

