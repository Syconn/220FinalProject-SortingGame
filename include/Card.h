//
// Created by Aidan on 10/6/2025.
//

#ifndef INC_220FINALMYVERSION_CARD_H
#define INC_220FINALMYVERSION_CARD_H
#include <string>
#include <utility>
#include <functional>
#include <iostream>

using std::string;
using std::function;

class Card {
    string name;
    string desc;
    function<void(int[], int)> func;
public:
    Card() : func(nullptr) {}
    Card(string name, string desc, const function<void(int[], int)> &func) : name(std::move(name)), desc(std::move(desc)), func(func) {}
    string details();
    void sortArray(int arr[], int size) const;
};


#endif //INC_220FINALMYVERSION_CARD_H