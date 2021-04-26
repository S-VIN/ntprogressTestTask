#pragma once

#include <string>
#include <iostream>
#include <exception>

using namespace std;

string normalize(string input) {
    //erase spaces
    while (input.find_first_of(" ") != string::npos) {
        input.erase(input.find_first_of(" "), 1);
    }
    //replace ',' to '.'
    while (input.find_first_of(",") != string::npos) {
        input[input.find_first_of(",")] = '.';
    }

    //check string to other symbols
    string allowed = "0123456789.()+-/*";
    for (auto item : input) {
        if (allowed.find_first_of(item) == string::npos) {
            throw logic_error("bad character in string");
        }
    }

    //check brackets
    int counterO = 0;
    int counterC = 0;
    for (auto item: input) {
        if (item == '(')
            counterO++;
        if (item == ')')
            counterC++;
    }
    if (counterC != counterO)
        throw logic_error("wrong brackets");

    return input;
}
