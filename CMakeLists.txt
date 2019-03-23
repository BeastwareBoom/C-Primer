cmake_minimum_required(VERSION 3.12)
project(CppPrimer)

set(CMAKE_CXX_STANDARD 11)

#cmake tutorial src
set(CMAKE_TUTORIAL cmake_tutorial/tutorial.cpp)

# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
        "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
        "${PROJECT_BINARY_DIR}/TutorialConfig.h"
)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")




set(SRC_CH01 ch01/main.cpp include/Sales_item.h ch01/1.20.cpp)

#WIN32
add_executable(${PROJECT_NAME} ${CMAKE_TUTORIAL} ${SRC_CH01})