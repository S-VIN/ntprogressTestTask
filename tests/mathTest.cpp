#include "catch.hpp"
#include "../src/math.h"

TEST_CASE("Solver class", "[s]"){
    CHECK(Solver::solveSimple(1, 2, '+') == 3);
    CHECK(Solver::solveSimple(2, 1, '-') == 1);
    CHECK(Solver::solveSimple(3, 2, '*') == 6);
    CHECK(Solver::solveSimple(6, 3, '/') == 2);
    CHECK(Solver::solveSimple(1.5, 2, '*') == 3);
    CHECK(Solver::solveSimple(1.11, 2.22, '+') == Approx(3.33).epsilon(0.001));
}