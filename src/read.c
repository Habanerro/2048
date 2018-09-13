#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int read_choice()
{
	char c[2];
	c[0] = -1;
	c[1] = 0;
	int n = -1;

	while (1) {
		printf("Ход:");
		scanf("%s", c);
		if (c[0] > 47 && c[0] < 58 && c[1] == 0) {
			c[0] = c[0] - '0';
			n = (int)c[0];
			return n;
		} else {
			printf("Incorrect!\n");
			c[0] = -1;
			c[1] = 0;
		}
	}
}
