cmake_minimum_required(VERSION 3.12)
project(CppPrimer)

set(CMAKE_CXX_STANDARD 11)

#cmake tutorial src
set(CMAKE_TUTORIAL cmake_tutorial/tutorial.cpp)


set(SRC_CH01 ch01/main.cpp include/Sales_item.h ch01/1.20.cpp)


#WIN32
add_executable(${PROJECT_NAME} ${CMAKE_TUTORIAL} ${SRC_CH01})