cmake_minimum_required(VERSION 3.12)
project(CppPrimer)

set(CMAKE_CXX_STANDARD 11)
# compile and link message in details
set(CMAKE_VERBOSE_MAKEFILE TRUE)

# add compile options
# https://stackoverflow.com/questions/11783932/how-do-i-add-a-linker-or-compile-flag-in-a-cmake-file
# https://cmake.org/cmake/help/latest/command/target_compile_options.html
# https://cmake.org/pipermail/cmake/2006-February/008370.html
#set(CMAKE_CXX_FLAGS_<type> "-fexceptions")

#-----------------------------------------------------------#
#----------------------CppPrimer Start----------------------#
#-----------------------------------------------------------#

#set(SRC_CH01 ch01/main.cpp include/Sales_item.h ch01/1.20.cpp)
# scans all files in the <dir> and stores in <var>
# Note: If CMakeList.txt is not modified after adding a new file,one needs to manually re-run CMake to refresh.
aux_source_directory(ch01 SRC_CH01)

#-----------------------------------------------------------#
#-----------------------CppPrimer End-----------------------#
#-----------------------------------------------------------#


# 参考 https://cmake.org/cmake-tutorial/

#-----------------------------------------------------------#
#--------------------CMakeTutorial Start--------------------#
#-----------------------------------------------------------#

# 参见 https://stackoverflow.com/questions/39481958/setting-cmake-install-prefix-from-cmakelists-txt-file/39485990
# Use this snippet *after* PROJECT(xxx):
IF (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    SET(CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR}/install
            CACHE PATH "used to determine the root of where the files will be installed." FORCE)
ENDIF (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
# may not work on windows
# https://cmake.org/cmake/help/v3.12/envvar/DESTDIR.html
#set(DESTDIR "D:/")

# should we use our own math functions?
# If no initial value is provided, OFF is used.
# -DUSE_MYMATH=ON to change the value
# Options are cached variables
# USE cmake-gui | File | Delete Cache to rm cache
# 参见 https://stackoverflow.com/questions/35744647/what-can-cause-a-cmake-option-not-work
option(USE_MYMATH "Use tutorial provided math implementation" ON)# ON

if (USE_MYMATH)

    # add an add_subdirectory call in the top level CMakeLists.txt file so that the library will get built.
    # This command tells CMake to look in said folder for another CMakeLists.txt file and execute that script,
    # so every subdirectory added this way must have a CMakeLists.txt file within.
    add_subdirectory(MathFunctions)

    # add include directory so that the MathFunctions/MathFunctions.h header file can be found for the function prototype
    #        下面两者均可
    #    include_directories("${PROJECT_SOURCE_DIR}/MathFunctions")
    list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/MathFunctions")

    # Note the use of a variable (EXTRA_LIBS in this case) to collect up any optional libraries to later be linked into the executable.
    # This is a common approach used to keep larger projects with many optional components clean.
    #    下面两者均可
    #    set(EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
    list(APPEND EXTRA_LIBS MathFunctions)

endif (USE_MYMATH)

#cmake tutorial src
set(CMAKE_TUTORIAL cmake_tutorial/tutorial.cpp)

# The version number.
set(Tutorial_VERSION_MAJOR 1)
set(Tutorial_VERSION_MINOR 0)
set(Tutorial_VERSION_PATCH 0)

# does this system provide the log and exp functions?
include(CheckSymbolExists)
set(CMAKE_REQUIRED_LIBRARIES "m")
check_symbol_exists(log "math.h" HAVE_LOG)
check_symbol_exists(exp "math.h" HAVE_EXP)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(
        "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
        "${PROJECT_BINARY_DIR}/TutorialConfig.h"
)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
#include_directories("${PROJECT_BINARY_DIR}")

#-----------------------------------------------------------#
#---------------------CMakeTutorial End---------------------#
#-----------------------------------------------------------#


#WIN32 ${CMAKE_TUTORIAL}
add_executable(${PROJECT_NAME}  ${SRC_CH01})


target_link_libraries(${PROJECT_NAME} ${EXTRA_LIBS})

# 代替上方 include_directories()
target_include_directories(${PROJECT_NAME} PUBLIC "${PROJECT_BINARY_DIR}" ${EXTRA_INCLUDES})

if (USE_MYMATH)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different # or using copy_directory followed with a dir
            ${PROJECT_BINARY_DIR}/MathFunctions/MathFunctions.dll
            $<TARGET_FILE_DIR:${PROJECT_NAME}>)# or using ${PROJECT_BINARY_DIR}
endif ()

# add the install targets. Run | Install or make install on linux
message(${CMAKE_INSTALL_PREFIX})
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" DESTINATION include)

# add test Configurations | ContinuousTest for test
#include(CTest)
#enable_testing()

#define a macro to simplify adding tests, then use it
macro(do_test arg result)
    add_test(TutorialComp${arg} ${PROJECT_NAME} ${arg})
    set_tests_properties(TutorialComp${arg}
            PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro(do_test)

# do a bunch of result based tests
do_test(25 "25 is 5")
do_test(-25 "-25 is 0")


# build a CPack driven installer package
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE
        "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${Tutorial_VERSION_PATCH}")

# NSIS not installed problem
# https://stackoverflow.com/questions/29754510/generating-an-installer-using-cmake-cpack-wix
# ZIP打普通压缩包 或者 WIX构建.msi(Microsoft Installer)包
set(CPACK_GENERATOR ZIP WIX)# 同时打包.zip和.msi
include(CPack)

# 定义函数，扫描指定路径并拷贝到binary所在路径
function(ITERATE_COPY dir)
    file(GLOB files ${dir})
    foreach (file ${files})
        MESSAGE(STATUS "ITERATE_COPY: copying ${file}")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                ${file} $<TARGET_FILE_DIR:${PROJECT_NAME}>)
    endforeach ()
endfunction(ITERATE_COPY)

# matching all files under docs dir
#ITERATE_COPY(docs/*)

# Where are the additional libraries installed? Note: provide includes
# path here, subsequent checks will resolve everything else
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/foo_module/" )