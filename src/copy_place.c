#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

void copy_place (int* pointer2, int* buffer) 
{
    int i;
    for (i = 0; i < 16; i++) {
        *(buffer + i) = *(pointer2 + i);
    }
}

