# built as a module
# SHARED for dynamic lib;STATIC for static lib,default when not given
add_library(MathFunctions mysqrt.cxx MathFunctions.h)

# TutorialConfig.h file not found: the .h file in build dir
target_include_directories(MathFunctions INTERFACE ${CMAKE_CURRENT_SOURCE_DIR} PRIVATE ${PROJECT_BINARY_DIR})

install (TARGETS MathFunctions DESTINATION bin)
install (FILES MathFunctions.h DESTINATION include)