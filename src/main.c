#include "rubiks.c"

int main() {
    int row = 3;
    int column = 3;
    Face *** rubiks = create_rubiks(row, column);
    init_rubiks(rubiks);
    while (menu(rubiks))
    {
        display_rubiks(rubiks, row, column);
    }
    printf("FIN");
    return 0;
}