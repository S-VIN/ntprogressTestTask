cmake_minimum_required(VERSION 3.16)
project(ntprogressTestTask)

set(CMAKE_CXX_STANDARD 20)

set(SRC_LIST main.cpp src/operations.h src/math.h)

add_executable(${PROJECT_NAME} ${SRC_LIST})

add_subdirectory(include/stringOperations)
add_subdirectory(tests)

target_link_libraries(${PROJECT_NAME} stringsOperations)