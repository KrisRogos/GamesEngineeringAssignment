#pragma once
#include <stdlib.h>

float RandomFloat (float min = 0, float max = 1)
{
    float random = ((float)rand () / (float)RAND_MAX); // generate a number
    float setSize = max - min; // get the size of the set of numbers available
    float result = random * setSize; // calculate the number
    return min + result; // return the number adjusted to the starting point of the random set

}