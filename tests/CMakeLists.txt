cmake_minimum_required(VERSION 3.16)
project(tests)

set(SRC_TESTS main.cpp catch.hpp normalizeTest.cpp)

add_executable(${PROJECT_NAME} ${SRC_TESTS})