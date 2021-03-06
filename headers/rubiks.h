#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../src/conio.h"

#ifndef RUBIKS_PROJECT
#define RUBIKS_PROJECT

typedef struct Face Face;

char * index_color(int index);

int side_to_index(char side);
int select_color(char color);
int random_num(int min, int max);
int opposide_side(int side);
int menu(Face *** rubiks);
int * create_tab(int size);

Face *** create_rubiks(int row, int column);


void init_rubiks(Face *** rubiks);
void display_rubiks(Face *** rubiks, int row, int column);
void fill_rubiks(Face *** rubiks);
void scramble_rubiks(Face *** rubiks, int num);

//mouvement
void front_anticlockwise(Face *** rubiks, int rotation );
void back_anticlockwise(Face *** rubiks, int rotation );
void up_anticlockwise(Face *** rubiks, int rotation );
void down_anticlockwise(Face *** rubiks, int rotation );
void right_anticlockwise(Face *** rubiks, int rotation );
void left_anticlockwise(Face *** rubiks, int rotation );

void front__clockwise(Face *** rubiks, int rotation );
void back__clockwise(Face *** rubiks, int rotation );
void up__clockwise(Face *** rubiks, int rotation );
void down__clockwise(Face *** rubiks, int rotation);
void right__clockwise(Face *** rubiks, int rotation );
void left__clockwise(Face *** rubiks, int rotation);

void vertical_rotation(Face *** rubiks);
void horizontal_rotation(Face *** rubiks);
void rotate(Face *** rubiks, int side);
void move_rubiks(Face *** rubiks);
void free_rubiks(Face *** rubiks);

//solution
void blue_edges(Face *** rubiks);
void red_edges(Face *** rubiks);
void green_edges(Face *** rubiks);
void orange_edges(Face *** rubiks);
void step_1(Face *** rubiks);
void step_2(Face *** rubiks);
void step2_right(Face *** rubiks);
void step2_up(Face *** rubiks);
void step2_down(Face *** rubiks);
void step2_left(Face *** rubiks);
void step_3(Face *** rubiks);
void step_4(Face *** rubiks);

#endif