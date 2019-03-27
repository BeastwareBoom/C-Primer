# built as a module

set(MATH_LIB MathFunctions)

set(MAKE_TABLE MakeTable)
# 1.create an executable
add_executable(${MAKE_TABLE} MakeTable.cpp)
# 2.add custom command
# ref https://cmake.org/cmake/help/latest/command/add_custom_command.html
add_custom_command(
#        2.1 create output file Table.h
        OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
#        2.2 pass it as argument to the exe
        COMMAND ${MAKE_TABLE} ${CMAKE_CURRENT_BINARY_DIR}/Table.h
#        2.3 serves as depend
        DEPENDS ${MAKE_TABLE}
)

# 3.  search path for include files
# directory scope
# https://stackoverflow.com/questions/31969547/what-is-the-difference-between-include-directories-and-target-include-directorie
include_directories(${CMAKE_CURRENT_BINARY_DIR})

# https://cmake.org/cmake/help/v3.13/prop_tgt/ENABLE_EXPORTS.html#prop_tgt:ENABLE_EXPORTS
#set(ENABLE_EXPORTS TRUE)

# 4. add .h to the main library
# SHARED for dynamic lib;STATIC for static lib,default when not given
add_library(${MATH_LIB} SHARED mysqrt.cxx ${CMAKE_CURRENT_BINARY_DIR}/Table.h)

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

# target scope
# TutorialConfig.h file not found: the .h file in build dir
target_include_directories(${MATH_LIB} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR} PRIVATE ${PROJECT_BINARY_DIR})

install (TARGETS ${MATH_LIB} DESTINATION bin)
install (FILES MathFunctions.h DESTINATION include)