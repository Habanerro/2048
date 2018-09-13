#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

void save (float Score)
{
    FILE *fpST;
    fpST = fopen ("C:/Users/Tailer/Desktop/2048/Record_titel.txt", "a");

    fprintf (fpST, "%.0f\n", Score);
}
