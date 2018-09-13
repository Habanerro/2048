#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

void print_field (int *pointer2, float Score, float plus)
{
    int i, j;
    int res;
    int goal = 0;
    printf ("\nYour score: %.0f (%.0f)\n\n", Score, plus);
    for (i = 0; i <= 3; i++) {
        for (j = 0; j <= 3; j++) {
            res = *(pointer2 + (i * 4) + j);
            if (res == 0) {
                printf ("  ..");
            } else {
                if (res == 11) goal = 1; // равен 2048
                printf ("%4.0f", pow (2.0, res));
            }
            }

            if (j != 3) {
                printf (" ");
            }
            printf ("\n\n");
            if(goal == 1) printf("Поздарвляем! Вы достигли ячейки 2048!\n");
        }
}

