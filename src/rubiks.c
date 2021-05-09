#include "../headers/rubiks.h"

typedef enum { B  = 4, W = 0, R = 3, G = 2, Y = 5, O = 1, LG=6 } T_COLOR ;
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
        case 6 :
            return "LG";    
    }
    return "LG"; 
}

/**
 * Raphael Barriet, Ahyl Pradhan.
 * Return dynamic table
*/
int * create_tab(int size) {
  return (int *)malloc(size);
}

int random_num(int min, int max) {
  srand(time(NULL));
  return (rand() % (max + 1 - min)) + min; 
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

/**
 * 
 * Raphael Barriet, Ahyl Pradhan. 
 * display rubiks;
 * 
*/
void display_rubiks(Face *** rubiks, int row, int column){

    int i,j;
    Face * square;
    char * over = "\n";
    char * empty_square = "\n      ";
    for(i = 0; i < row; i++) {
      printf("%s", empty_square);
      for(j = 0; j < column; j++) {
          square = &rubiks[0][i][j];   
          printf("%s", index_color(square->t_color));
          printf("%s", " ");
      } 
      printf("%s", over); 
    }

    for(i = 0; i < row; i++) {
       for(j = 0; j < column; j++) {
           Face * square = &rubiks[1][i][j];
           printf("%s", index_color(square->t_color));
           printf("%s", " "); 
       }
       for(j = 0; j < column; j++) {
           Face * square = &rubiks[2][i][j];
           printf("%s", index_color(square->t_color));
           printf("%s", " ");
       }
       for(j = 0; j < column; j++) {
           Face * square = &rubiks[3][i][j];
           printf("%s", index_color(square->t_color));
           printf("%s", " ");
       }
       for(j = 0; j < column; j++) {
           Face * square = &rubiks[4][i][j];
           printf("%s", index_color(square->t_color));
           printf("%s", " ");
       }
       printf("%s", over); 
    } 

    for(i = 0; i < 3; i++) {
      printf("%s", empty_square);  
      for(j = 0; j < column; j++) {
          square = &rubiks[5][i][j];   
          printf("%s", index_color(square->t_color));
          printf("%s", " ");
      } 
    }   
}

void blank_rubiks(Face *** rubiks) {
    int i,j, k;
    for(i = 0; i < 6; i++) {
       for(j = 0; j < 3; j++){
         for(k = 0; k < 3; k++) {
            rubiks[i][j][k].t_color = LG;
        }
      }
    } 
}

void fill_rubiks(Face *** rubiks) {
    return;
} 



void front__clockwise(Face *** rubiks, int rotation){
    int i;
    for(i = 0; i < rotation; i++) {
      rotate_horizontal(rubiks, FRONT);
    }
}

void back__clockwise(Face *** rubiks, int rotation ){
    int i;
    for(i = 0; i < rotation; i++) {
      rotate_horizontal(rubiks, BACK);
    }
}

void up__clockwise(Face *** rubiks, int rotation ){
    int i;
    Face temp, temp_2, temp_3;
    for(i=0; i < rotation; i++) {
        rotate(rubiks, UP);
    }

    for(i=0; i < 3; i++) {
     temp = rubiks[LEFT][i][0];
     rubiks[LEFT][i][0] = rubiks[FRONT][0][i];

     temp_2 = rubiks[BACK][2][i];
     rubiks[BACK][2][i] = temp; 

     temp_3 = rubiks[RIGHT][i][2];
     rubiks[RIGHT][i][2] = temp_2;

     rubiks[FRONT][0][i] = temp_3; 
    }
}

void down__clockwise(Face *** rubiks, int rotation ){
    int i;
    Face temp, temp_2, temp_3;
    for(i=0; i < rotation; i++) {
        rotate(rubiks, DOWN);
    }

    for(i=0; i < 3; i++) {
     temp = rubiks[LEFT][i][2];
     rubiks[LEFT][i][2] = rubiks[FRONT][2][i];

     temp_2 = rubiks[BACK][0][i];
     rubiks[BACK][0][i] = temp; 

     temp_3 = rubiks[RIGHT][i][0];
     rubiks[RIGHT][i][0] = temp_2;

     rubiks[FRONT][2][i] = temp_3; 
    }
}

void right__clockwise(Face *** rubiks, int rotation ){
    int i;
    Face temp, temp_2, temp_3;
    for(i=0; i < rotation; i++) {
        rotate(rubiks, RIGHT);
    }

    for(i=0; i < 3; i++) {
     temp = rubiks[DOWN][i][2];
     rubiks[DOWN][i][2] = rubiks[FRONT][i][2];

     temp_2 = rubiks[BACK][i][2];
     rubiks[BACK][i][2] = temp; 

     temp_3 = rubiks[UP][i][0];
     rubiks[UP][i][0] = temp_2;

     rubiks[FRONT][i][2] = temp_3; 
    }
}

void left__clockwise(Face *** rubiks, int rotation ){
    int i;
    Face temp, temp_2, temp_3;
    for(i=0; i < rotation; i++) {
        rotate(rubiks, LEFT);
    }

    for(i=0; i < 3; i++) {
     temp = rubiks[DOWN][i][0];
     rubiks[DOWN][i][0] = rubiks[FRONT][2][i];

     temp_2 = rubiks[BACK][0][i];
     rubiks[BACK][0][i] = temp; 

     temp_3 = rubiks[UP][i][2];
     rubiks[UP][i][2] = temp_2;

     rubiks[FRONT][2][i] = temp_3; 
    }
}

void front_anticlockwise(Face *** rubiks, int rotation ){
    int i;
    for(i = 0; i < 3; i++) {
        front__clockwise(rubiks, rotation);
    }
}

void back_anticlockwise(Face *** rubiks, int rotation ){
    int i;
    for(i = 0; i < 3; i++) {
        back__clockwise(rubiks, rotation);
    }
}

void up_anticlockwise(Face *** rubiks, int rotation ){
    int i;
    for(i = 0; i < 3; i++) {
        up__clockwise(rubiks, rotation);
    }
}

void down_anticlockwise(Face *** rubiks, int rotation ){
    int i;
    for(i = 0; i < 3; i++) {
        down__clockwise(rubiks, rotation);
    }
}

void right_anticlockwise(Face *** rubiks, int rotation ){
    int i;
    for(i = 0; i < 3; i++) {
        right__clockwise(rubiks, rotation);
    }
}

void left_anticlockwise(Face *** rubiks, int rotation ){
    int i;
    for(i = 0; i < 3; i++) {
        left__clockwise(rubiks, rotation);
    }
}

void rotate_horizontal(Face *** rubiks, int side) {
    Face * stock; 
    Face * stock_2;
    int k;

    rotate(rubiks, side);

    switch (side)
    {
    case 0:
        k = 0;
        break;
    case 5:
        k = 2;
        break;
    default:
        k = 0;
    } 

    stock = rubiks[G][k];
    rubiks[G][k] = rubiks[R][k];

    stock_2 = rubiks[B][k];
    rubiks[B][k] = rubiks[O][k];

    rubiks[O][k] = stock;

    rubiks[R][k] = stock_2;
}

void rotate(Face *** rubiks, int side) {
    Face ** temp = (Face **)malloc(3 * sizeof(Face*));
    Face ** temp_2;

    int j, r, k;
    for(r = 0; r < 3; r++) {
        temp[r] = (Face *)malloc(3 * sizeof(Face));
    }
    for(j = 0; j < 3; j++) {
        temp[2][2 - j] = rubiks[side][j][2];
        temp[1][2 - j] = rubiks[side][j][1]; 
        temp[0][2 - j] = rubiks[side][j][0];
    }
    temp_2 = rubiks[side];
    rubiks[side] = temp; 
    free(temp_2); 
}

void horizontal_rotation(Face *** rubiks){
   Face ** temp = rubiks[0];
   rubiks[0] = rubiks[5];
   rubiks[5] = temp;
   free(temp);
}

void vertical_rotation(Face *** rubiks) {
   Face ** temp = rubiks[DOWN];
   Face ** temp_2 = rubiks[FRONT];

   rubiks[DOWN] = rubiks[UP];
   rubiks[FRONT] = rubiks[BACK];

   rubiks[UP] = temp;
   rubiks[BACK] = temp_2;
}
