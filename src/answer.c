#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

int answer ()
{
    int n = -1;
    char c[2];
    c[0] = -1;
    c[1] = 0;

    printf("Are you sure? ('1'(yes) or '0'(no))?\n");
    
    while (1) {
        scanf("%s", c);
        if ((c[0] == 49 || c[0] == 48) && c[1] == 0) {
            c[0] = c[0] - '0';
            n = (int)c[0];
            return n;
        } else {
            printf("Непонятно...\n");
            c[0] = -1;
            c[1] = 0;
        }
    }
}
