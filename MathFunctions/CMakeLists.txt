# built as a module

set(MATH_LIB MathFunctions)

# https://cmake.org/cmake/help/v3.13/prop_tgt/ENABLE_EXPORTS.html#prop_tgt:ENABLE_EXPORTS
#set(ENABLE_EXPORTS TRUE)

# SHARED for dynamic lib;STATIC for static lib,default when not given
add_library(${MATH_LIB} SHARED mysqrt.cxx)

# TutorialConfig.h file not found: the .h file in build dir
target_include_directories(${MATH_LIB} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR} PRIVATE ${PROJECT_BINARY_DIR})

install (TARGETS ${MATH_LIB} DESTINATION bin)
install (FILES MathFunctions.h DESTINATION include)