#include "catch.hpp"
#include "../include/stringOperations/stringsOperations.h"
#include "../src/operations.h"

TEST_CASE("check normalize input string", "[nis]") {
    CHECK(normalize(" 1 2 3 45 ") == "12345");
    CHECK(normalize(" ") == "");
    CHECK(normalize(",123,12,3") == ".123.12.3");
    CHECK_NOTHROW(normalize("1234567890./()*/+-"));
    CHECK_THROWS_WITH(normalize(""), "empty input");
    CHECK_THROWS_WITH(normalize("1234a321"), "bad character in string");
    CHECK_THROWS_WITH(normalize("111(1(1((()))2)))"), "wrong brackets");
}

TEST_CASE("check breaking string up", "[cbsu]") {
    CHECK(breakUp("123+321") == vector<string>({"123", "+", "321"}));
    CHECK(breakUp("1+2") == vector<string>({"1", "+", "2"}));
    CHECK(breakUp("1+1-1*1/1(1)1") ==
          vector<string>({"1", "+", "1", "-", "1", "*", "1", "/", "1", "(", "1", ")", "1"}));
    CHECK(breakUp("(123+321)") == vector<string>({"(", "123", "+", "321", ")"}));
    CHECK(breakUp("((123+321))") == vector<string>({"(", "(", "123", "+", "321", ")", ")"}));
    CHECK(breakUp("(1)*(1)") == vector<string>({"(", "1", ")", "*", "(", "1", ")"}));
}

