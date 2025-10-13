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
    winServer = new WinServer(8080, this);
}

void Game::run() {
    while (running) {
        winServer->poll();
    }
}

Game::~Game() {
    delete winServer;
}


