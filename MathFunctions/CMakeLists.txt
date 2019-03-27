# built as a module

set(MATH_LIB MathFunctions)

# https://cmake.org/cmake/help/v3.13/prop_tgt/ENABLE_EXPORTS.html#prop_tgt:ENABLE_EXPORTS
#set(ENABLE_EXPORTS TRUE)

# SHARED for dynamic lib;STATIC for static lib,default when not given
add_library(${MATH_LIB} SHARED mysqrt.cxx)

#SET(CMAKE_BUILD_TYPE RELEASE)# Default|Debug|Release|RelWithDebInfo|MinSizeRel
MESSAGE(STATUS "CMAKE_BUILD_TYPE:${CMAKE_BUILD_TYPE}")

#if (MSVC_VERSION)
#    IF (CMAKE_BUILD_TYPE MATCHES Release|Win32)
#        set(COMPILE_OPTIONS "/GF /Od /W3 /Zi /Od /MDd /NOLOGO")
#        set(LINK_OPTIONS "/SUBSYSTEM:CONSOLE /MACHINE:X86 /MANIFEST /NOLOGO /DEBUG")
#        set_target_properties(${MATH_LIB} PROPERTIES LINK_FLAGS ${LINK_OPTIONS} COMPILE_FLAGS ${COMPILE_OPTIONS})
#        message(STATUS "COMPILE_OPTIONS:${COMPILE_OPTIONS}")
#        message(STATUS "LINK_OPTIONS:${LINK_OPTIONS}")
#    elseIF (CMAKE_BUILD_TYPE MATCHES Debug|Win32)
#        set(COMPILE_OPTIONS "/GF /Od /W3 /Zi /Od /MDd")
#        set(LINK_OPTIONS "/SUBSYSTEM:CONSOLE /INCREMENTAL:NO /MACHINE:X86 /MANIFEST /NOLOGO /DEBUG")
#        set_target_properties(${MATH_LIB} PROPERTIES LINK_FLAGS ${LINK_OPTIONS} COMPILE_FLAGS ${COMPILE_OPTIONS})
#        message(STATUS "COMPILE_OPTIONS:${COMPILE_OPTIONS}")
#        message(STATUS "LINK_OPTIONS:${LINK_OPTIONS}")
#
#    Endif ()
#endif (MSVC_VERSION)

# TutorialConfig.h file not found: the .h file in build dir
target_include_directories(${MATH_LIB} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR} PRIVATE ${PROJECT_BINARY_DIR})

install (TARGETS ${MATH_LIB} DESTINATION bin)
install (FILES MathFunctions.h DESTINATION include)