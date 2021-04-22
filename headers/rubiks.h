#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef HEADER_FILE
#define HEADER_FILE

typedef struct Face Face;

int * create_tab(int size);
char * index_color(int index);
int side_to_index(char side);
Face *** create_rubiks(int row, int column);
int select_color(char color);
void init_rubiks(Face *** rubiks);
void display_rubiks(Face *** rubiks, int row, int column);
void move_rubiks(Face *** rubiks);
void free_rubiks(Face *** rubiks);
void move_rubiks(Face *** rubiks);

#endif