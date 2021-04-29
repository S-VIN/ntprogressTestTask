#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <sstream>
#include "include/stringOperations/stringsOperations.h"
#include "src/operations.h"

using namespace std;

int main() {
    string input = "";
    getline(cin, input);
    check(input);
    input = normalize(input);

    stringstream ss;
    ss.setf(std::ios::fixed);
    ss.precision(2);
    ss << stringToDouble(solveExpression(breakUp(input)));

    string result = ss.str();
    for(int i = 0; i < 3; i++)
        if(result[result.size() - 1] == '0' || result[result.size() - 1] == '.'){
            result.erase(result.end() - 1);
        }else{
            break;
        }
    cout << result;

    return 0;
}