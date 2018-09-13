#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

void main(void)
{
	unix_clear();
	printf("\nHello!\nДобро пожаловть в игру 2048!\n\n");
	display_menu();

	int *pointer = generate_place();
	int *buffer = generate_place();
	int *safe_buffer = generate_place();
	int choice = -1;
	float score = 0.0, plus = 0.0;
	int flag_of_end = 0;
	int flag_of_back = 1;
	copy_place(pointer, buffer); // 2 принимает хначение 1 поэлементно
	copy_place(pointer, safe_buffer);
	print_field(pointer, score, plus);

	while ((flag_of_end == 0) && (endgame(pointer) == 0)) {
		choice = read_choice();
		plus = 0.0;
		switch(choice) {
			case 0: // новая игра
				if(answer()) {
					a: // к черту 100 флагов и завязанные циклы
					free(pointer);
					free(buffer);
					pointer = generate_place();
					buffer = generate_place();
					copy_place(pointer, buffer);

					int choice = -1;
					float score = 0.0;
					int flag_of_end = 0;

					unix_clear();
					print_field(pointer, score, 0);
				}
				break;
			case 1: // завершить игру
				flag_of_end = answer();
				break;
			case 2: // вниз
				copy_place(pointer, buffer);
				plus += mergeoff(pointer , 2);
				if (plus != -1) {
					score += plus;
					generate(pointer);
					copy_place(buffer, safe_buffer);
					unix_clear();
					print_field(pointer, score, plus);
					flag_of_back = 1;
				} else {
					// Откат буфера
					copy_place(safe_buffer, buffer);
				}
				break;
			case 3: // вывести рекорды
				printf("Records:\n");
				print_record();
				break;
			case 4: // влево
				copy_place(pointer, buffer);
				plus += mergeoff(pointer , 4);
				if (plus != -1) {
					score += plus;
					generate(pointer);
					copy_place(buffer, safe_buffer);
					unix_clear();
					print_field(pointer, score, plus);
					flag_of_back = 1;
				} else {
					// Откат буфера
					copy_place(safe_buffer, buffer);
				}
				break;
			case 5: // вывести меню
				display_menu();
				break;
			case 6: // вправо
				copy_place(pointer, buffer);
				plus += mergeoff(pointer , 6);
				if (plus != -1) {
					score += plus;
					generate(pointer);
					copy_place(buffer, safe_buffer);
					unix_clear();
					print_field(pointer, score, plus);
					flag_of_back = 1;
				} else {
					// Откат буфера
					copy_place(safe_buffer, buffer);
				}
				break;
			case 7: // шаг назад
				if (flag_of_back == 1) {
					plus -= (2 * pow(2.0, comeback(pointer, buffer))); // отрицательное число (ранее зануляли)
					score += plus;
					if (score < 0) {
						score = 0.0;
					}
					unix_clear();
					print_field(pointer, score, plus);
					flag_of_back = 0;
				} else {
					printf("Можно сделать только 1 шаг назад.\n");
				}
				break;
			case 8: // вверх
				copy_place(pointer, buffer);
				plus += mergeoff(pointer , 8);
				if (plus != -1) {
					score += plus;
					generate(pointer);
					copy_place(buffer, safe_buffer);
					unix_clear();
					print_field(pointer, score, plus);
					flag_of_back = 1;
				} else {
					// Откат буфера
					copy_place(safe_buffer, buffer);
				}
				break;
			case 9: // сохранить рекорд
				printf("Это действие приведет к старту новой игры!\n");
				if (answer()) {
					save(score);
					goto a;
				}
				break;
		}
	}

	if (endgame(pointer) != 0) {
		save(score);
	}

	unix_exit();
	unix_clear();
}
