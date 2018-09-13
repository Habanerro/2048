#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

int *generate_place ()
{
    int *array = calloc (16, sizeof(int));
    generate(array);
    generate(array);
    return array;
}
