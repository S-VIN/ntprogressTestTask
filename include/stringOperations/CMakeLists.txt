cmake_minimum_required(VERSION 3.19)

project(stringOperations)

set(STRING_SOURCE stringsOperations.h stringsOperations.cpp)

add_library(stringsOperations STATIC ${STRING_SOURCE})