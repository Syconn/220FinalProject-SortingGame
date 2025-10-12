//
// Created by Aidan on 10/12/2025.
//

#include "Game.h"

#include <iostream>

Game::Game() {
    setup();
    run();
}

void Game::setup() {
    winServer = new WinServer(8080);
}

void Game::run() {
    while (running) {
        cout << "polling" << endl;
        const int poll = winServer->poll();
        cout << poll << endl;
    }
}

Game::~Game() {
    delete winServer;
}


