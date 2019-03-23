# built as a module
# SHARED for dynamic lib;STATIC for static lib,default when not given
add_library(MathFunctions mysqrt.cxx)

install (TARGETS MathFunctions DESTINATION bin)
install (FILES MathFunctions.h DESTINATION include)