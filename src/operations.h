#pragma once

#include <string>
#include <stack>
#include <iostream>
#include <exception>
#include <vector>
#include "math.h"

using namespace std;

string normalize(string input) {
    if (input == "") {
        throw logic_error("empty input");
    }

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

vector<string> breakUp(string input) {
    vector<string> result;
    result.push_back("");
    string operation = "*/+-()";
    for (auto item : input) {
        if (operation.find_first_of(item) != string::npos) {
            result.push_back(string(1, item));
            result.push_back("");
        } else {
            result[result.size() - 1] += item;
        }
    }
    //clear from zero string (double brackets)
    for (int i = 0; i < result.size(); i++) {
        if (result[i] == "") {
            result.erase(result.begin() + i);
        }
    }
    return result;
}

string solveExpressionWithoutBrackets(vector<string> input){
    //solve * / expression first
    int size = input.size();
    for(int i = 0; i < size; i++){
        if(input[i] == "/" || input[i] == "*"){
            input[i - 1] = floatToString(Solver::solveSimple(stringToFloat(input[i - 1]), stringToFloat(input[i + 1]) , input[i][0]));
            input.erase(input.begin() + i);
            input.erase(input.begin() + i);
            i = 0;
            size = input.size();
        }
    }
    //solve + -
    for(int i = 0; i < size; i++){
        if(input[i] == "+" || input[i] == "-"){
            input[i - 1] = floatToString(Solver::solveSimple(stringToFloat(input[i - 1]), stringToFloat(input[i + 1]) , input[i][0]));
            input.erase(input.begin() + i);
            input.erase(input.begin() + i);
            i = 0;
            size = input.size();
        }
    }
    return input[0];
}

string solveExpression(vector<string> input){
    for(int i = 0; i < input.size(); i++){
        if(input[i] == ")"){
            vector<string> temp;
            while(input[i] != "("){
                temp.push_back(input[i]);
                i--;
                input.erase(input.begin() + i);
            }
            input[i] = solveExpressionWithoutBrackets(temp);
            i = 0;
        }
    }
    return input[0];
}