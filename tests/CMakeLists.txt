cmake_minimum_required(VERSION 3.16)
project(tests)

set(SRC_TESTS
        testMain.cpp
        catch.hpp
        normalizeTest.cpp
        ../src/operations.h
        ../include/stringOperations/stringsOperations.h
        ../include/stringOperations/stringsOperations.cpp
        ../src/math.h)

add_executable(${PROJECT_NAME} ${SRC_TESTS})