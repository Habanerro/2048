
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "header.h"

void generate (int *pointer2)
{
    int i, j = 0;
    int *optionalarray = calloc (16, sizeof(int));
    int random;
    for (i = 0; i < 16; i++) {
        *(optionalarray + i) = -1;
    }

    for (i = 0; i < 16; i++) {
        if (*(pointer2 + i) == 0) {
            *(optionalarray + j) = i;
            j++;
        }
    }
    srand( time(NULL) );
    random = rand () % j;
    *(pointer2 + *(optionalarray + random)) = 1;
}
