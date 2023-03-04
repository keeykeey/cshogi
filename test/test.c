#include <stdio.h>
#include <stdlib.h>
#include "../src/piece.h"
#include "../board.h"

int test_piece()
{
    piece_type_e ptype = GYOKU;
    piece_t *piece = init_piece(ptype);
    
    if (piece->type == 0) {
        free(piece);
        return 0;
    } else {
        free(piece);
        return 1;
    }
}

int test_board()
{
    board_t *board = init_board();
    
    if (board->square[0]->position == 91) {
        free(board);
        return 0;
    } else {
        free(board);
        return 1;
    }
}

int main(void) 
{
    int failed = test_piece();
    failed += test_board();

    printf("FAILED : %d\n",failed);
    return failed;
}