//
// Created by Aidan on 10/6/2025.
//

#ifndef INC_220FINALMYVERSION_CARD_H
#define INC_220FINALMYVERSION_CARD_H
#include <string>
#include "functional"

using std::string;
using std::function;

class Card {
    string name;
    string desc;
    function<void(int[], int)> func;
public:
    Card() : name(""), desc(""), func(nullptr) {}
    Card(const string &name, const string &desc, const function<void(int[], int)> &func) : name(name), desc(desc), func(func) {};
};


#endif //INC_220FINALMYVERSION_CARD_H