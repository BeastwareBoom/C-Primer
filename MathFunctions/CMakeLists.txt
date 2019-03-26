# built as a module

set(MATH_LIB MathFunctions)

# SHARED for dynamic lib;STATIC for static lib,default when not given
add_library(${MATH_LIB} mysqrt.cxx)

# TutorialConfig.h file not found: the .h file in build dir
target_include_directories(${MATH_LIB} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR} PRIVATE ${PROJECT_BINARY_DIR})

install (TARGETS ${MATH_LIB} DESTINATION bin)
install (FILES MathFunctions.h DESTINATION include)