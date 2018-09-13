#include "header.h"

void print_record ()
{
	FILE* fp = fopen("Record_titel.txt", "r");
	float s = 0.0;

	while (fscanf(fp, "%f\n", &s) != EOF) {
		printf("%.0f\n", s);
	}
}
