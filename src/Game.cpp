//
// Created by Aidan on 10/12/2025.
//

#include "Game.h"

Game::Game() {
    setup();
    run();
}

void Game::setup() {
    winServer = new WinServer(8080, this); // Start Web Server
    srand(time(nullptr));
}

void Game::setupPlay() {
    playing = true; // Signal Playing

    sortArray = new int[sortArraySize]; // Create Array
    for (int i = 0; i < sortArraySize; i++) sortArray[i] = rand() % (maxVal - minVal + 1) + minVal;
}

void Game::run() {
    while (running) {
        winServer->poll();
        if (!playing && gameState == GameLoop) setupPlay();
    }
}

Game::~Game() {
    delete winServer;
}


