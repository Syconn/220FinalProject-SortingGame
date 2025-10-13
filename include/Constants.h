//
// Created by Aidan on 10/12/2025.
//

#ifndef INC_220FINALMYVERSION_CONSTANTS_H
#define INC_220FINALMYVERSION_CONSTANTS_H

#include <string>

using namespace std;

// GameStates
static const string MainMenu = "menu";
static const string GameLoop = "gameLoop";

// Request Codes
static constexpr int NO_RET = 0;
static constexpr int ERROR = -1;
static constexpr int PAGE = 1;
static constexpr int SET_PAGE = 2;
static constexpr int OPTIONS = -2;

#endif //INC_220FINALMYVERSION_CONSTANTS_H