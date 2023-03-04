#include <stdio.h>
#include <stdlib.h>
#include "./board.h"
#include "./src/piece.h"

board_t *
init_board()
{
    board_t *board;
    board = calloc(1, sizeof(board_t));

    square_t tmp_square;
    tmp_square.position = 91;

    board->square[0] = &tmp_square;
    return board;
}