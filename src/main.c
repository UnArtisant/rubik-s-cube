#include "rubiks.c"

int main() {
    int row = 3;
    int column = 3;
    Face *** rubiks = create_rubiks(row, column); 
    init_rubiks(rubiks);
    move_rubiks(rubiks);
    return 0;
}