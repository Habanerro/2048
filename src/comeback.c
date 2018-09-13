#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

int comeback (int *pointer2, int *buffer)
{
    int i, max = 0;
    for (i = 0; i < 16; i++) {
        if (max < *(pointer2 + i)) {
            max = *(pointer2 + i);
        }
        *(pointer2 + i) = *(buffer + i);
    }
    return max;
}


