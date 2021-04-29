#include <string>

using namespace std;

double stringToDouble(string input){
    return atof(input.c_str());
}

string doubleToString(double input){
    return to_string(input);
}

string addMinus(string input){
    if(input[0] == '-'){
        input.erase(input.begin());
    }else{
        input.insert(input.begin(), '-');
    }
    return input;
}