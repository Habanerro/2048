#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int answer ();
void adaptive_win();
int comeback (int *pointer2, int *buffer);
void copy_place (int* pointer2, int* buffer);
void display_menu ();
int endgame (int *pointer2);
void generate (int *pointer2);
int *generate_place ();
float mergeoff (int* pointer2, int choice);
void print_field (int *pointer2, float Score, float plus);
void print_record ();
int read_choice();
void save (float Score);
void win_clear();
void win_exit();
void unix_exit();
void unix_clear();
