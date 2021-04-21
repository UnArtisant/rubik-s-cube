#include "../headers/rubiks.h"

typedef enum { B  = 4, W = 0, R = 3, G = 2, Y = 5, O = 1 } T_COLOR ;
typedef enum { UP  = 4, FRONT = 0, RIGHT = 3, DOWN = 2, BACK = 5, LEFT = 1 } C_SIDE;

struct Face {
  T_COLOR t_color;
  C_SIDE c_side;
};

char * index_color(int index) {
   switch(index)
    {
        case 0  :
            return "W";
        case 1 :
            return "0";
        case 2  :
            return "G";
        case 3 :
            return "R";
        case 4:
            return "B";
        case 5 :
            return "Y";
    }
    return "W"; 
}

/**
 * Raphael Barriet, Ahyl Pradhan.
 * Return dynamic table
*/
int * create_tab(int size) {
  return (int *)malloc(size);
}

/**
 * Raphael Barriet, Ahyl Pradhan.
 * Return index from side.
*/
int side_to_index(char side){
    switch(side)
    {
        case UP  :
            return UP;
        case FRONT :
            return FRONT;
        case RIGHT   :
            return RIGHT;
        case DOWN :
            return DOWN;
        case BACK:
            return BACK;
        case LEFT:
            return LEFT;
    }
    return 0;
}

/**
 * Raphael Barriet, Ahyl Pradhan.
 * Return side from color.
*/
int select_color(char color) {
    switch(color)
    {
        case B  :
            return UP;
        case W :
            return FRONT;
        case R  :
            return RIGHT;
        case G :
            return DOWN;
        case Y:
            return BACK;
        case O:
            return LEFT;
    }
    return 0;
}

/**
 * 
 * Raphael Barriet, Ahyl Pradhan. 
 * structure rubiks;
 * 
*/
Face *** create_rubiks(int row, int column) {
   int i, r;
   Face *** container = (Face ***)malloc(6 * sizeof(Face**));
   for(i = 0; i < 6; i++) {
       container[i] = (Face **)malloc(3 * sizeof(Face*)); 
       for(r = 0; r < column; r++) {
              container[i][r] = (Face *)malloc(3 * sizeof(Face)); 
        }      
   }
   return container;
}

/**
 * 
 * Raphael Barriet, Ahyl Pradhan. 
 * init structure rubiks;
 * 
*/
void init_rubiks(Face *** rubiks) {
  T_COLOR faces[6] = {W, O, G, R, B, Y};
  C_SIDE sides[6] = {FRONT, LEFT, DOWN, RIGHT, UP, BACK};

  int i,j, k;
  for(i = 0; i < 6; i++) {
     for(j = 0; j < 3; j++){
       for(k = 0; k < 3; k++) {
          Face temp = {faces[i], sides[i]};
          rubiks[i][j][k] = temp;
       }
     }
  } 
}

void display_rubiks(Face *** rubiks, int row, int column){

    int i,j;
    Face * square;
    char * over = "\n";
    char * empty_square = "\n   ";
    for(i = 0; i < row; i++) {
      printf("%s", empty_square);
      for(j = 0; j < column; j++) {
          square = &rubiks[0][i][j];   
          printf("%s", index_color(square->t_color));
      } 
      printf("%s", over); 
    }

    for(i = 0; i < row; i++) {
       for(j = 0; j < column; j++) {
           Face * square = &rubiks[1][i][j];
           printf("%s", index_color(square->t_color)); 
       }
       for(j = 0; j < column; j++) {
           Face * square = &rubiks[2][i][j];
           printf("%s", index_color(square->t_color));
       }
       for(j = 0; j < column; j++) {
           Face * square = &rubiks[3][i][j];
           printf("%s", index_color(square->t_color));
       }
       for(j = 0; j < column; j++) {
           Face * square = &rubiks[4][i][j];
           printf("%s", index_color(square->t_color));
       }
       printf("%s", over); 
    } 

    for(i = 0; i < 3; i++) {
      printf("%s", empty_square);  
      for(j = 0; j < column; j++) {
          square = &rubiks[5][i][j];   
          printf("%s", index_color(square->t_color));
      } 
    }   
}