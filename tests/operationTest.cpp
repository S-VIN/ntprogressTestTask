#include "catch.hpp"
#include "../include/stringOperations/stringsOperations.h"
#include "../src/operations.h"

TEST_CASE("normalise func", "[nf]") {
    CHECK(normalize(" 1 2 3 45 ") == "12345");
    CHECK(normalize(" ") == "");
    CHECK(normalize(",123,12,3") == ".123.12.3");
    CHECK_NOTHROW(normalize("1234567890./()*/+-"));
    CHECK_THROWS_WITH(normalize(""), "empty input");
    CHECK_THROWS_WITH(normalize("1234a321"), "bad character in string");
    CHECK_THROWS_WITH(normalize("111(1(1((()))2)))"), "wrong brackets");
}

TEST_CASE("breakUp", "[bu]") {
    CHECK(breakUp("123+321") == vector<string>({"123", "+", "321"}));
    CHECK(breakUp("1+2") == vector<string>({"1", "+", "2"}));
    CHECK(breakUp("1+1-1*1/1(1)1") ==
          vector<string>({"1", "+", "1", "-", "1", "*", "1", "/", "1", "(", "1", ")", "1"}));
    CHECK(breakUp("(123+321)") == vector<string>({"(", "123", "+", "321", ")"}));
    CHECK(breakUp("((123+321))") == vector<string>({"(", "(", "123", "+", "321", ")", ")"}));
    CHECK(breakUp("(1)*(1)") == vector<string>({"(", "1", ")", "*", "(", "1", ")"}));
}

TEST_CASE("solveExpressionWithoutBrackets func", "[sewb]"){
    CHECK(solveExpressionWithoutBrackets(breakUp("1+2")) == "3.000000");
    CHECK(solveExpressionWithoutBrackets(breakUp("2-1")) == "1.000000");
    CHECK(solveExpressionWithoutBrackets(breakUp("1*2")) == "2.000000");
    CHECK(solveExpressionWithoutBrackets(breakUp("3/2")) == "1.500000");
    CHECK(solveExpressionWithoutBrackets(breakUp("1.1+1.2")) == "2.300000");
    CHECK(solveExpressionWithoutBrackets(breakUp("1+2*3")) == "7.000000");
    CHECK(solveExpressionWithoutBrackets(breakUp("1*2+3*4/2")) == "8.000000");
    CHECK(solveExpressionWithoutBrackets(breakUp("1*2+1*3+1*4")) == "9.000000");
    CHECK(solveExpressionWithoutBrackets(breakUp("1.0+1.5*2.0")) == "4.000000");
}

TEST_CASE("solveExpression func", "[sef]"){
    CHECK(solveExpression(breakUp("(1+2)")) == "3.000000");
}

