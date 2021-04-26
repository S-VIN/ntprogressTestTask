cmake_minimum_required(VERSION 3.16)
project(ntprogressTestTask)

set(CMAKE_CXX_STANDARD 20)

#enable_testing()

set(SRC_LIST main.cpp)

add_executable(${PROJECT_NAME} ${SRC_LIST})

add_subdirectory(src)
add_subdirectory(tests)

target_link_libraries(${PROJECT_NAME} stringsOperations)
