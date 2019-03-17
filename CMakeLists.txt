cmake_minimum_required(VERSION 3.12)
project(CppPrimer)

set(CMAKE_CXX_STANDARD 11)

set(SRC_CH01 ch01/main.cpp)

#WIN32
add_executable(${PROJECT_NAME} ${SRC_CH01})