#include <string>

using namespace std;

float stringToFloat(string input){
    return atof(input.c_str());
}

string floatToString(float input){
    return to_string(input);
}