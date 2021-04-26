#include "catch.hpp"
#include "../src/stringsOperations.h"
TEST_CASE("check normalize input string", "[u]") {
    REQUIRE(normalize(" 1 2 3 45 ") == "1245");
}