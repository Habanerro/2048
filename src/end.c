#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

int endgame (int *pointer2)
{
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
             if ((*(pointer2 + (i * 4) + j)) > 13) {
                 return 1;
             }
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
             if ((*(pointer2 + (i * 4) + j)) == 0) {
                 return 0;
             }
        }
    }
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++) {
            if ((*(pointer2 + (i * 4) + j)) == (*(pointer2 + (i * 4) + j + 1))) {
                return 0;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 4; j++) {
             if ((*(pointer2 + (i * 4) + j)) == (*(pointer2 + ((i + 1) * 4) + j))) {
                 return 0;
             }
        }
    }
    return 1;
}
