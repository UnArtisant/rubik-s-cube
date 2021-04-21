#include "rubiks.c"

int main() {
    int row = 3;
    int column = 3;
    Face *** rubiks = create_rubiks(row, column); 
    init_rubiks(rubiks);
    display_rubiks(rubiks, row, column);
    return 0;
}