#include <string>

using namespace std;

double stringTodouble(string input){
    return atof(input.c_str());
}

string doubleToString(double input){
    return to_string(input);
}