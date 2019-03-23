cmake_minimum_required(VERSION 3.12)
project(CppPrimer)

set(CMAKE_CXX_STANDARD 11)

#-----------------------------------------------------------#
#----------------------CppPrimer Start----------------------#
#-----------------------------------------------------------#

set(SRC_CH01 ch01/main.cpp include/Sales_item.h ch01/1.20.cpp)

#-----------------------------------------------------------#
#-----------------------CppPrimer End-----------------------#
#-----------------------------------------------------------#




# 参考 https://cmake.org/cmake-tutorial/

#-----------------------------------------------------------#
#--------------------CMakeTutorial Start--------------------#
#-----------------------------------------------------------#

# should we use our own math functions?
# If no initial value is provided, OFF is used.
option(USE_MYMATH
        "Use tutorial provided math implementation")

if (USE_MYMATH)

    # add include directory so that the MathFunctions/MathFunctions.h header file can be found for the function prototype
    include_directories("${PROJECT_SOURCE_DIR}/MathFunctions")

    # add an add_subdirectory call in the top level CMakeLists.txt file so that the library will get built.
    add_subdirectory(MathFunctions)

    # Note the use of a variable (EXTRA_LIBS in this case) to collect up any optional libraries to later be linked into the executable.
    # This is a common approach used to keep larger projects with many optional components clean.
    set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)

endif (USE_MYMATH)

#cmake tutorial src
set(CMAKE_TUTORIAL cmake_tutorial/tutorial.cpp)

# The version number.
set(Tutorial_VERSION_MAJOR 1)
set(Tutorial_VERSION_MINOR 0)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(
        "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
        "${PROJECT_BINARY_DIR}/TutorialConfig.h"
)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")


#-----------------------------------------------------------#
#---------------------CMakeTutorial End---------------------#
#-----------------------------------------------------------#


#WIN32
add_executable(${PROJECT_NAME} ${CMAKE_TUTORIAL} ${SRC_CH01})


target_link_libraries(${PROJECT_NAME} ${EXTRA_LIBS})