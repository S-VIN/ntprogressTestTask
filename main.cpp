#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <sstream>
#include "src/stringsOperations.h"
using namespace std;



int main(){
    string input = "";
    getline(cin, input);
    cout << normalize(input);


    return 0;
}