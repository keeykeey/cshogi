#include <stdio.h>
#include <stdlib.h>
#include "./piece.h"
#include "./board.h"

int main(void)
{
    board_t *board = init_board();

    printf("GAME START\n");
    printf("%d |",board->square[0]->position);
    putchar('\n');

    free(board);
    return 0;
}