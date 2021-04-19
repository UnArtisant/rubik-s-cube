int * create_tab(int size) {
  return (int *)malloc(size);
}

/**
 * 
 * structure rubiks;
 * 
 * int up[3][3]    = { {0,0,0}, {0,0,0}, {0,0,0} };
 * int side[row][column] = { {side_num,side_num,side_num}, {side_num,side_num,side_num}, {side_num,side_num,side_num} };
 * 
* int rubicks[6][3][3] = { up, front, right, down, back, left }; 
*/
int * create_rubiks(int row, int column) {
   int i, r;
   int size_container = row * column * sizeof(int);
   int * container = create_tab(6 * size_container);
   for(i = 0; i < 6; i++) {
       int *side = create_tab(size_container);
       for(r = 0; r < column; r++) {
              int * row_side = create_tab(sizeof(int) * column);
              side[r] = row_side;
        }      
    container[i];
   }
   return container;
}