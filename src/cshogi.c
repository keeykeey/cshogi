#include <stdio.h>
#include <stdlib.h>
#include "./piece.h"
#include "./board.h"

int main(void)
{
    board_t *board = init_board();

    printf("GAME START\n");
    
    for (int i = 0; i < 9; i++) {
        printf(" | ");
        for (int j=0; j < 9; j++) {
            printf("%d | ",board->square[i * 9 + j]->position);
        }
        putchar('\n');
    }

    free(board);
    return 0;
}