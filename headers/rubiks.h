#include <stdio.h>
#include <stdlib.h>

#ifndef HEADER_FILE
#define HEADER_FILE

typedef struct Face Face;

int * create_tab(int size);
Face *** create_rubiks(int row, int column);
int select_color(int color);

#endif