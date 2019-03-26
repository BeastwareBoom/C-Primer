// A simple program that computes the square root of a number

//printf with a stream arg at first
//https://en.cppreference.com/w/cpp/io/c/fprintf
//atof: string to float

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include "TutorialConfig.h"
#ifdef USE_MYMATH
#include "MathFunctions.h"
#endif

int main (int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stdout,"%s Version %d.%d\n", argv[0],
                Tutorial_VERSION_MAJOR,
                Tutorial_VERSION_MINOR);
        fprintf(stdout,"Usage: %s number\n",argv[0]);
        return 1;
    }

    double inputValue = atof(argv[1]);

#ifdef USE_MYMATH
    double outputValue = mysqrt(inputValue);
#else
    double outputValue = sqrt(inputValue);
#endif

    fprintf(stdout,"The square root of %g is %g\n",
            inputValue, outputValue);
    return 0;
}