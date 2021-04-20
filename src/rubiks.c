#include "../headers/rubiks.h"

typedef enum { BLUE  = 0, WHITE = 1, RED = 2, GREEN = 3, YELLOW = 4, ORANGE = 5 } T_COLOR ;
typedef enum { UP  = 0, FRONT = 1, RIGHT = 2, DOWN = 3, BACK = 4, LEFT = 5 } C_SIDE;

struct Face {
  int face[3][3];
  C_SIDE c_side;
};


/**
 * Raphael Barriet, Ahyl Pradhan.
 * create table
*/
int * create_tab(int size) {
  return (int *)malloc(size);
}

/**
 * 
 * Raphael Barriet, Ahyl Pradhan. 
 * structure rubiks;
 * 
*/
Face *** create_rubiks(int row, int column) {
   int i, r;
   Face ***container = (Face ***)malloc(6 * sizeof(Face**));
   for(i = 0; i < 6; i++) {
       container[i] = (Face **)malloc(3 * sizeof(Face*)); 
       for(r = 0; r < column; r++) {
              container[i][r] = (Face *)malloc(3 * sizeof(Face)); 
        }      
   }
   return container;
}

int select_color(int color) {
    switch(color)
    {
        case BLUE  :
            return 0;
        case WHITE :
            return 1;
        case RED   :
            return 2;
        case GREEN :
            return 3;
        case YELLOW:
            return 4;
        case ORANGE:
            return 5;
    }
    return 0;
}