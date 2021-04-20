#include <stdio.h>
#include "../src/rubiks.c"

#ifndef HEADER_FILE
#define HEADER_FILE

int * create_tab(int size);
int * create_rubiks(int row, int column);
int select_color(T_COLOR);

#endif