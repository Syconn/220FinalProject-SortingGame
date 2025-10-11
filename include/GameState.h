//
// Created by Aidan on 10/10/2025.
//

#ifndef INC_220FINALMYVERSION_GAMESTATE_H
#define INC_220FINALMYVERSION_GAMESTATE_H

#include <string>

using std::string;

enum class GameState {
    MainMenu,
    Play,
};

int handleRequest(const string& request);

#endif //INC_220FINALMYVERSION_GAMESTATE_H