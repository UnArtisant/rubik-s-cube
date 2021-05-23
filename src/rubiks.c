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

int random_num(int nMin, int nMax) {
  srand(time(NULL));
  return rand()%((nMax+1)-nMin) + nMin;
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
int select_color(int color) {
    switch(color)
    {
        case B  :
            return BLUE;
        case W :
            return WHITE;
        case R  :
            return RED;
        case G :
            return GREEN;
        case Y:
            return YELLOW;
        case O:
            return MAGENTA;
    }
    return LIGHTGRAY;
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
          //c_textcolor(select_color(square->t_color)); 
          printf("%s", index_color(square->t_color));
          printf("%s", " ");
      } 
      printf("%s", over); 
    }

    for(i = 0; i < row; i++) {
       for(j = 0; j < column; j++) {
           Face * square = &rubiks[1][i][j];
           //c_textcolor(select_color(square->t_color)); 
           printf("%s", index_color(square->t_color));
           printf("%s", " "); 
       }
       for(j = 0; j < column; j++) {
           Face * square = &rubiks[2][i][j];
           //c_textcolor(select_color(square->t_color)); 
           printf("%s", index_color(square->t_color));
           printf("%s", " ");
       }
       for(j = 0; j < column; j++) {
           Face * square = &rubiks[3][i][j];
           //c_textcolor(select_color(square->t_color)); 
           printf("%s", index_color(square->t_color));
           printf("%s", " ");
       }
       for(j = 0; j < column; j++) {
           Face * square = &rubiks[4][i][j];
           //c_textcolor(select_color(square->t_color)); 
           printf("%s", index_color(square->t_color));
           printf("%s", " ");
       }
       printf("%s", over); 
       //c_textcolor(select_color(WHITE)); 
    } 

    for(i = 0; i < 3; i++) {
      printf("%s", empty_square);  
      for(j = 0; j < column; j++) {
          square = &rubiks[5][i][j];   
          printf("%s", index_color(square->t_color));
          printf("%s", " ");
      } 
    }  
   printf("%s", over);  
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


/**
 * Ahyl PRADHAN, Raphael BARRIET
 * move front side 
*/
void front__clockwise(Face *** rubiks, int rotation){
    int i;
    Face * stock; 
    Face * stock_2;
    for(i = 0; i < rotation; i++) {
    
     rotate(rubiks, FRONT);

     stock = rubiks[DOWN][0];
     rubiks[DOWN][0] = rubiks[RIGHT][0];

     stock_2 = rubiks[UP][0];
     rubiks[UP][0] = rubiks[LEFT][0];

     rubiks[LEFT][0] = stock;

     rubiks[RIGHT][0] = stock_2;
    }
}

/**
 * Ahyl PRADHAN, Raphael BARRIET
 * move back side 
*/
void back__clockwise(Face *** rubiks, int rotation ){
    int i;
    Face * stock; 
    Face * stock_2;
    for(i = 0; i < rotation; i++) {
    
     rotate(rubiks, BACK);

     stock = rubiks[DOWN][2];
     rubiks[DOWN][2] = rubiks[LEFT][2];

     stock_2 = rubiks[UP][2];
     rubiks[UP][2] = rubiks[RIGHT][2];

     rubiks[RIGHT][2] = stock;

     rubiks[LEFT][2] = stock_2;
    }
}

/**
 * Ahyl PRADHAN, Raphael BARRIET
 * move up side 
*/
void up__clockwise(Face *** rubiks, int rotation ){
    int i;
    Face temp, temp_2, temp_3;
    for(i=0; i < rotation; i++) {
        rotate(rubiks, UP);
    

    for(i=0; i < 3; i++) {
     temp = rubiks[LEFT][i][0];
     rubiks[LEFT][i][0] = rubiks[FRONT][0][2 - i];

     temp_2 = rubiks[BACK][2][i];
     rubiks[BACK][2][i] = temp; 

     temp_3 = rubiks[RIGHT][2 - i][2];
     rubiks[RIGHT][2 - i][2] = temp_2;

     rubiks[FRONT][0][2 - i] = temp_3; 
    }
    }
}

/**
 * Ahyl PRADHAN, Raphael BARRIET
 * move right side 
*/
void down__clockwise(Face *** rubiks, int rotation ){
    int i;
    Face temp, temp_2, temp_3;
    for(i=0; i < rotation; i++) {
        rotate(rubiks, DOWN);
    

    for(i=0; i < 3; i++) {
     temp = rubiks[RIGHT][i][0];
     rubiks[RIGHT][i][0] = rubiks[FRONT][2][i];

     temp_2 = rubiks[BACK][0][2 - i];
     rubiks[BACK][0][2 - i] = temp; 

     temp_3 = rubiks[LEFT][2 - i][2];
     rubiks[LEFT][2 - i][2] = temp_2;

     rubiks[FRONT][2][i] = temp_3; 
    }
    }
}

/**
 * Ahyl PRADHAN, Raphael BARRIET
 * move right side 
*/
void right__clockwise(Face *** rubiks, int rotation ){
    int i;
    Face temp, temp_2, temp_3;
    for(i=0; i < rotation; i++) {
        rotate(rubiks, RIGHT);

    for(i=0; i < 3; i++) {
     temp = rubiks[DOWN][i][2];
     rubiks[DOWN][i][2] = rubiks[BACK][i][2];

     temp_2 = rubiks[FRONT][i][2];
     rubiks[FRONT][i][2] = temp; 

     temp_3 = rubiks[UP][2 - i][0];
     rubiks[UP][2 - i][0] = temp_2;

     rubiks[BACK][i][2] = temp_3; 
    }
    }
}

/**
 * Ahyl PRADHAN, Raphael BARRIET
 * move left side 
*/
void left__clockwise(Face *** rubiks, int rotation ){
    int i;
    Face temp, temp_2, temp_3;
    for(i=0; i < rotation; i++) {
        rotate(rubiks, LEFT);
    

    for(i=0; i < 3; i++) {
     temp = rubiks[BACK][i][0];
     rubiks[BACK][i][0] = rubiks[DOWN][i][0];

     temp_2 = rubiks[UP][2 - i][2];
     rubiks[UP][2 - i][2] = temp; 

     temp_3 = rubiks[FRONT][i][0];
     rubiks[FRONT][i][0] = temp_2;

     rubiks[DOWN][i][0] = temp_3; 
    }
    }
}

void front_anticlockwise(Face *** rubiks, int rotation ){
    int i;
    for(i = 0; i < 3 * rotation; i++) {
        front__clockwise(rubiks, 1);
    }
}

void back_anticlockwise(Face *** rubiks, int rotation ){
    int i;
    for(i = 0; i < 3 * rotation; i++) {
        back__clockwise(rubiks, 1);
    }
}

void up_anticlockwise(Face *** rubiks, int rotation ){
    int i;
    for(i = 0; i < 3 * rotation; i++) {
        up__clockwise(rubiks, 1);
    }
}

void down_anticlockwise(Face *** rubiks, int rotation ){
    int i;
    for(i = 0; i < 3 * rotation; i++) {
        down__clockwise(rubiks, 1);
    }
}

void right_anticlockwise(Face *** rubiks, int rotation ){
    int i;
    for(i = 0; i < 3 * rotation; i++) {
        right__clockwise(rubiks, 1);
    }
}

void left_anticlockwise(Face *** rubiks, int rotation ){
    int i;
    for(i = 0; i < 3 * rotation; i++) {
        left__clockwise(rubiks, 1);
    }
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
}

// penser au arrete 
void horizontal_rotation(Face *** rubiks){
   Face ** temp = rubiks[0];
   rubiks[0] = rubiks[5];
   rubiks[5] = temp;
}

//penser au arrete
void vertical_rotation(Face *** rubiks) {
   Face ** temp = rubiks[DOWN];
   Face ** temp_2 = rubiks[FRONT];

   rubiks[DOWN] = rubiks[UP];
   rubiks[FRONT] = rubiks[BACK];

   rubiks[UP] = temp;
   rubiks[BACK] = temp_2;
}

void scramble_rubiks(Face *** rubiks, int num){
    srand(time(NULL));
    int hasard,i;
    const int MAX = 12, MIN = 1;
    for(i=0; i < num; i++) {
        hasard = (rand() % (MAX - MIN + 1)) + MIN;
        switch (hasard) {
            case 1 :
                front__clockwise(rubiks,1);
                break;
            case 2:
                front_anticlockwise(rubiks,1);
                break;
            case 3:
                back__clockwise(rubiks,1);
                break;
            case 4:
                back_anticlockwise(rubiks,1);
                break;
            case 5:
                right__clockwise(rubiks,1);
                break;
            case 6:
                right_anticlockwise(rubiks,1);
                break;
            case 7:
                left_anticlockwise(rubiks,1);
                break;
            case 8:
                left_anticlockwise(rubiks,1);
                break;
            case 9:
                up_anticlockwise(rubiks,1);
                break;
            case 10:
                up_anticlockwise(rubiks,1);
                break;
            case 11:
                down__clockwise(rubiks,1);
                break;
            case 12:
                down_anticlockwise(rubiks,1);
                break;
            default:
                printf("Erreur\n");
        }
    }
}

void free_rubiks(Face *** rubiks) {
    int i,j;
    for(i = 0; i < 6; i++) {
        for(j = 0; j < 3; j++) {
                free(rubiks[i][j]);
        }
        free(rubiks[i]);
    }
    free(rubiks);
}

void move_rubiks (Face *** rubiks) {
    int choix_face;
    int choix_move;
    do {
        printf("quelle face souhaitez-vous bouger ?\n");
        printf("%d : UP, %d : FRONT, %d : DOWN, %d : LEFT, %d : RIGHT, %d : BACK ?\n", UP, FRONT, DOWN, LEFT, RIGHT, BACK);
        scanf("%d", &choix_face);
    } while(choix_face < 0 || choix_face > 5);
    do {
        printf("Taper 1 pour faire tourner la face dans le sens horaire \nTaper 2 pour la faire tourner dans le sens anti-horaire\nTaper 3 pour faire une rotation horizontale\nTaper 4 pour faire une rotation verticale\n");
        scanf("%d", &choix_move);
    } while (choix_move < 0 || choix_move > 4);
        switch (choix_move) {
            case 1 :
              if(choix_face == UP) {
                up__clockwise(rubiks, 1);
              }
              if(choix_face == FRONT) {
                 front__clockwise(rubiks, 1); 
              }
              if(choix_face == DOWN) {
                  down__clockwise(rubiks, 1);
              }
              if(choix_face == LEFT) {
                  left__clockwise(rubiks, 1);
              }
              if(choix_face == RIGHT) {
                  right__clockwise(rubiks, 1);
              }
              if(choix_face == BACK) {
                  back__clockwise(rubiks, 1);
              }
              break;
            case 2 :
              if(choix_face == UP) {
                  up_anticlockwise(rubiks, 1);
              }
              if(choix_face == FRONT) {
                  front_anticlockwise(rubiks,1);
              }
              if(choix_face == DOWN) {
                  down_anticlockwise(rubiks, 1);
              }
              if(choix_face == LEFT) {
                  left_anticlockwise(rubiks, 1);
              }
              if(choix_face == RIGHT) {
                  right_anticlockwise(rubiks, 1);
              }
              if(choix_face == BACK) {
                  back_anticlockwise(rubiks, 1);
              }
              break;
            case 3 :
               horizontal_rotation(rubiks);
               break;
            case 4 :
               vertical_rotation(rubiks);
                break;
        }
}

//solution step 1

//edges function

void blue_edges(Face *** rubiks) {
 int i, k, j = 0; 
 while( 
           !(*(&rubiks[UP][1][2].t_color) == B && *(&rubiks[LEFT][1][0].t_color) == W) &&
           !(*(&rubiks[UP][2][1].t_color) == B && *(&rubiks[BACK][2][1].t_color) == W) 
         ) 
    {
        left__clockwise(rubiks, 1);
        back__clockwise(rubiks, 1);

        if(i > 5) {
            down__clockwise(rubiks, 1);
            front__clockwise(rubiks, 1);
            i = 0;
        }
        if(j > 200) {
            break;
        }
        j++;
        i++;
    }

    k = (*(&rubiks[UP][1][2].t_color) == B && *(&rubiks[LEFT][1][0].t_color) == W) ? 1 : 2;
    up_anticlockwise(rubiks, k);
}

void green_edges(Face *** rubiks) {
   int i,j, k=0;
   while( 
           !(*(&rubiks[DOWN][1][2].t_color) == G && *(&rubiks[RIGHT][1][0].t_color) == W) &&
           !(*(&rubiks[DOWN][2][1].t_color) == G && *(&rubiks[BACK][0][1].t_color) == W) 
         ) 
    {
     down__clockwise(rubiks, 1);
     back__clockwise(rubiks, 1);
     if(i > 5 && i < 10) {
         up__clockwise(rubiks, 1);
         back__clockwise(rubiks, 1);
         up_anticlockwise(rubiks, 1);
     } 
     if(i > 10 && i < 15) {
         up_anticlockwise(rubiks, 1);
         back__clockwise(rubiks, 1);
         up__clockwise(rubiks, 1); 
     }
     if(i > 15 && i < 20) {
         left__clockwise(rubiks, 1);
         back__clockwise(rubiks, 1);
         left_anticlockwise(rubiks, 1);
     } 
     if(i > 20 && i < 25) {
         left_anticlockwise(rubiks, 1);
         back__clockwise(rubiks, 1);
         left__clockwise(rubiks, 1); 
     }
     if(i > 25 && i < 30) {
         right__clockwise(rubiks, 1);
         back__clockwise(rubiks, 1);
         right_anticlockwise(rubiks, 1);
     } 
     if(i > 30 && i < 35) {
         right_anticlockwise(rubiks, 1);
         back__clockwise(rubiks, 1);
         right__clockwise(rubiks, 1); 
         i=0;
     }
     if(j > 200) {
            break;
        }
        j++;
     i++;
    }

    k = (*(&rubiks[DOWN][1][2].t_color) == G && *(&rubiks[RIGHT][1][0].t_color) == W) ? 1 : 2;
    down_anticlockwise(rubiks, k); 
}

void red_edges(Face *** rubiks) {
   int i, k, j = 0;
   while( 
           !(*(&rubiks[RIGHT][1][2].t_color) == R && *(&rubiks[UP][1][0].t_color) == W) &&
           !(*(&rubiks[RIGHT][2][1].t_color) == R && *(&rubiks[BACK][1][2].t_color) == W) 
         ) 
    {
     right__clockwise(rubiks, 1);
     back__clockwise(rubiks, 1);
     if(i > 5 && i < 10) {
         down__clockwise(rubiks, 1);
         back__clockwise(rubiks, 1);
         down_anticlockwise(rubiks, 1);
         i=0;
     }
     if(i > 10 && i < 15) {
         down_anticlockwise(rubiks, 1);
         back__clockwise(rubiks, 1);
         down__clockwise(rubiks, 1); 
     }
     if(i > 15 && i < 20) {
         up__clockwise(rubiks, 1);
         back__clockwise(rubiks, 1);
         up_anticlockwise(rubiks, 1);
     } 
     if(i > 20 && i < 25) {
         up_anticlockwise(rubiks, 1);
         back__clockwise(rubiks, 1);
         up__clockwise(rubiks, 1); 
     }
     if(i > 25 && i < 30) {
         left__clockwise(rubiks, 1);
         back__clockwise(rubiks, 1);
         left_anticlockwise(rubiks, 1);
     } 
     if(i > 30 && i < 35) {
         left_anticlockwise(rubiks, 1);
         back__clockwise(rubiks, 1);
         left__clockwise(rubiks, 1); 
         i=0;
     }
     if(j > 200) {
            break;
     }
     j++;
     i++;
    }

    //step 3
    k = (*(&rubiks[RIGHT][1][2].t_color) == R && *(&rubiks[UP][1][0].t_color) == W) ? 1 : 2;
    right_anticlockwise(rubiks, k); 
}

void orange_edges(Face *** rubiks) {
   int i, k, j = 0;
   while( 
           !(*(&rubiks[LEFT][1][2].t_color) == O && *(&rubiks[DOWN][1][0].t_color) == W) &&
           !(*(&rubiks[LEFT][2][1].t_color) == O && *(&rubiks[BACK][1][0].t_color) == W) 
         ) 
    {
     left__clockwise(rubiks, 1);
     back__clockwise(rubiks, 1);
     if(i > 5 && i < 10) {
         right__clockwise(rubiks, 1);
         back__clockwise(rubiks, 1);
         right_anticlockwise(rubiks, 1);
     } 
     if(i > 10 && i < 15) {
         right_anticlockwise(rubiks, 1);
         back__clockwise(rubiks, 1);
         right__clockwise(rubiks, 1); 
     }
     if(i > 15 && i < 20) {
         up__clockwise(rubiks, 1);
         back__clockwise(rubiks, 1);
         up_anticlockwise(rubiks, 1);
     } 
     if(i > 20 && i < 25) {
         up_anticlockwise(rubiks, 1);
         back__clockwise(rubiks, 1);
         up__clockwise(rubiks, 1); 
     }
     if(i > 25 && i < 30) {
         down__clockwise(rubiks, 1);
         back__clockwise(rubiks, 1);
         down_anticlockwise(rubiks, 1);
     } 
     if(i > 30 && i < 35) {
         down_anticlockwise(rubiks, 1);
         back__clockwise(rubiks, 1);
         down__clockwise(rubiks, 1); 
         i=0;
     }
     if(j > 200) {
            break;
        }
     j++;
     i++;
    }

    //step 3
    k = (*(&rubiks[LEFT][1][2].t_color) == O && *(&rubiks[RIGHT][1][0].t_color) == W) ? 1 : 2;
    left_anticlockwise(rubiks, k); 
}

void step_1(Face *** rubiks) {

    int i, k = 0;

    // we want the white to be in front
    if(*(&rubiks[FRONT][1][1].t_color) != W) horizontal_rotation(rubiks);
    if(*(&rubiks[UP][1][1].t_color) != B) vertical_rotation(rubiks);

    blue_edges(rubiks);
    green_edges(rubiks);
    red_edges(rubiks);
    orange_edges(rubiks); 

    if(
        !(*(&rubiks[UP][0][1].t_color) == B && *(&rubiks[FRONT][0][1].t_color) == W) ||
        !(*(&rubiks[DOWN][0][1].t_color) == G && *(&rubiks[FRONT][2][1].t_color) == W) ||
        !(*(&rubiks[RIGHT][0][1].t_color) == R && *(&rubiks[FRONT][1][2].t_color) == W) ||
        !(*(&rubiks[LEFT][0][1].t_color) == O && *(&rubiks[FRONT][1][0].t_color) == W)
        )
    {
      scramble_rubiks(rubiks, 5);
      step_1(rubiks);
    }

}

void step_2(Face *** rubiks) {
    step2_right(rubiks);
    step2_up(rubiks);

} 


void step2_right(Face *** rubiks) {
   int i;

   while (
        *(&rubiks[RIGHT][2][0].t_color) != R ||
        *(&rubiks[DOWN][2][2].t_color) != W 
        )
    {
        for(i = 0; i < 3; i++) {
          back__clockwise(rubiks, 1);
          if(*(&rubiks[RIGHT][2][0].t_color) == R &&
          *(&rubiks[DOWN][2][2].t_color) == W) {
              break;
          }
        }

        if(*(&rubiks[RIGHT][2][0].t_color) == R &&
          *(&rubiks[DOWN][2][2].t_color) == W) {
              break;
        }

        down__clockwise(rubiks, 1);
        back__clockwise(rubiks, 1);
        down_anticlockwise(rubiks, 1);

        for(i = 0; i < 3; i++) {
          back__clockwise(rubiks, 1);
          if(*(&rubiks[RIGHT][2][0].t_color) == R &&
          *(&rubiks[DOWN][2][2].t_color) == W) {
              break;
          }
        }

        down_anticlockwise(rubiks, 1);
        back__clockwise(rubiks, 1);
        down__clockwise(rubiks, 1);
        back__clockwise(rubiks, 2);

        if(*(&rubiks[RIGHT][2][0].t_color) == R &&
          *(&rubiks[DOWN][2][2].t_color) == W) {
              break;
        }

        up__clockwise(rubiks, 1);
        back_anticlockwise(rubiks, 1);
        up_anticlockwise(rubiks, 1);

        if(*(&rubiks[RIGHT][2][0].t_color) == R &&
          *(&rubiks[DOWN][2][2].t_color) == W) {
              break;
        }

        up_anticlockwise(rubiks, 1);
        back_anticlockwise(rubiks, 2);
        up__clockwise(rubiks, 1);

        if(*(&rubiks[RIGHT][2][0].t_color) == R &&
          *(&rubiks[DOWN][2][2].t_color) == W) {
              break;
        }

        right__clockwise(rubiks, 1);
        back_anticlockwise(rubiks, 1);
        right_anticlockwise(rubiks,1);
        
        if(*(&rubiks[RIGHT][2][0].t_color) == R &&
          *(&rubiks[DOWN][2][2].t_color) == W) {
              break;
        }

        right_anticlockwise(rubiks, 1);
        back__clockwise(rubiks, 1);
        right__clockwise(rubiks,1);
        back_anticlockwise(rubiks, 1);
        
        if(*(&rubiks[RIGHT][2][0].t_color) == R &&
          *(&rubiks[DOWN][2][2].t_color) == W) {
              break;
        }

        left__clockwise(rubiks, 1);
        back__clockwise(rubiks, 1);
        left_anticlockwise(rubiks,1);
        
        if(*(&rubiks[RIGHT][2][0].t_color) == R &&
          *(&rubiks[DOWN][2][2].t_color) == W) {
              break;
        }

        left_anticlockwise(rubiks, 1);
        back_anticlockwise(rubiks, 1);
        left__clockwise(rubiks,1);
        

    }

    right__clockwise(rubiks, 1);
    down_anticlockwise(rubiks, 1);
    right_anticlockwise(rubiks, 1);
    down__clockwise(rubiks, 1);
    
}

void step2_up(Face *** rubiks) {
   int i; 
   while (
        *(&rubiks[UP][2][0].t_color) != B ||
        *(&rubiks[RIGHT][2][2].t_color) != W 
        )
    {

      for(i = 0; i < 3; i++) {
          back__clockwise(rubiks, 1);
          if(*(&rubiks[UP][2][0].t_color) == B &&
              *(&rubiks[RIGHT][2][2].t_color) == W) 
              {
                break;
              }
        }

        if(*(&rubiks[UP][2][0].t_color) == B &&
           *(&rubiks[RIGHT][2][2].t_color) == W) 
          {
            break;
          }  

      right__clockwise(rubiks, 1);
      back__clockwise(rubiks, 1);
      right_anticlockwise(rubiks,1);
      back_anticlockwise(rubiks,1);
        
        if(*(&rubiks[UP][2][0].t_color) == B &&
           *(&rubiks[RIGHT][2][2].t_color) == W) 
          {
            break;
          }

      left__clockwise(rubiks, 1);
      back_anticlockwise(rubiks, 2);
      left_anticlockwise(rubiks,1);
        
        if(*(&rubiks[UP][2][0].t_color) == B &&
           *(&rubiks[RIGHT][2][2].t_color) == W) 
          {
            break;
          }

      left_anticlockwise(rubiks, 1);
      back_anticlockwise(rubiks, 1);
      left__clockwise(rubiks,1); 

      if(*(&rubiks[UP][2][0].t_color) == B &&
           *(&rubiks[RIGHT][2][2].t_color) == W) 
          {
            break;
          } 

       down_anticlockwise(rubiks, 1);
       back_anticlockwise(rubiks, 2);
       down__clockwise(rubiks, 1);

    } 

    up__clockwise(rubiks, 1);
    right_anticlockwise(rubiks, 1);
    up_anticlockwise(rubiks, 1);
    right__clockwise(rubiks, 1);
}


int menu(Face *** rubiks){
    int choice;
    printf("\n------------------------------------------------------------------------------------------\n"
           "1 : Mélanger    2:Initialiser    3:Vider    4:Jouer    5:REmplir    6:Resoudre    7:Sortir\n"
           "------------------------------------------------------------------------------------------\n");
    fflush(stdin);
    scanf("%d",&choice);
    switch(choice){
        case 1:
            scramble_rubiks(rubiks, 50);
            break;
        case 2:
            init_rubiks(rubiks);
            break;
        case 3:
            blank_rubiks(rubiks);
            break;
        case 4:
            move_rubiks(rubiks);
            break;
        case 5:
            //fillRubiks
            break;
        case 6:
            step_1(rubiks);
            step_2(rubiks);
            break;
        case 7:
            return 0;
        default:
            printf("Error\n");
    }
    return 1;
}

