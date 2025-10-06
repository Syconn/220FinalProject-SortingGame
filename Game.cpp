//
// Created by Aidan on 10/2/2025.
//

#include "Game.h"

Game::Game() {
    srand(time(nullptr));
    setupArrayLength();
    generateArrayNumbers();
    play();
}

void Game::setupArrayLength() {
    std::cout << "TESTING How long do you want the array to be?" << std::endl;
    string selectionStr;
    getline(cin, selectionStr);
    arraySize = stoi(selectionStr);
}

void Game::generateArrayNumbers() {
    numbers = new int[arraySize];
    for (int i = 0; i < arraySize; i++) numbers[i] = rand() % (maxVal - minVal + 1) + minVal;
}

int Game::selectAlgorithm(const string options[], const int size) {
    string selectionStr;
    for (int i = 0; i < size; i++) cout << options[i] << ", ";
    cout << endl << "Pick an Algorithm (1-" << size << ')' << endl;
    getline(cin, selectionStr);
    int selection = stoi(selectionStr);
    if (selection <= size && selection >= 1) {
        cout << "You selected " << options[selection - 1] << endl;
    } else {
        cout << "You selected an invalid selection" << endl;
    }
    return selection;
}

void Game::play() {
    const string movesStr[] = {"Buble Sort", "Selection Sort", "Insertion Sort"};
    void (*moves[])(int[], int) = { bubbleSort, selectionSort, insertionSort };
    while (!isSorted(numbers, arraySize)) {
        constexpr int funcSize = 3;
        printArray(numbers, arraySize);
        int selection = selectAlgorithm(movesStr, funcSize);
        if (selection <= funcSize && selection >= 1) moves[selection - 1](numbers, arraySize);
    }
    printArray(numbers, arraySize);
    cout << "Congrats Your Sorted the Array" << endl;
}

