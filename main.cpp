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
    input = normalize(input);
    solveExpressionWithoutBrackets(breakUp(input));

    return 0;
}