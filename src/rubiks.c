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
  int random = rand()%((nMax+1)-nMin) + nMin;
  printf("%d", random);
  return random; 
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

void scramble_rubiks(Face *** rubiks){
    srand(time(NULL));
    int hasard,i;
    const int MAX = 14, MIN = 1;
    for(i=0; i < 50; i++) {
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
            case 13:
                horizontal_rotation(rubiks);
                break;
            case 14:
                vertical_rotation(rubiks);
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
            case 3 :
               horizontal_rotation(rubiks);
            case 4 :
               vertical_rotation(rubiks);
                ;
        }
        display_rubiks(rubiks, 3, 3);
}
