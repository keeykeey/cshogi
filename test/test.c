#include <stdio.h>
#include <stdlib.h>
#include "../src/piece.h"
#include "../src/board.h"

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

int test_board_91()
{
    board_t *board = init_board();
    
    if (board->square[0]->position == 91) {
        free(board);
        return 0;
    } else {
        free(board);
        printf("failed in test_board_91 : expect 91 but got %d\n",board->square[0]->position);
        return 1;
    }
}

int test_board_82()
{
    board_t *board = init_board();
    
    if (board->square[10]->position == 82) {
        free(board);
        return 0;
    } else {
        printf("failed in test_board_82 : expect 82 but got %d\n",board->square[10]->position);
        free(board);
        return 1;
    }
}

int test_board_19()
{
    board_t *board = init_board();
    
    if (board->square[80]->position == 19) {
        free(board);
        return 0;
    } else {
        printf("failed in test_board_19 : expect 19 but got %d\n",board->square[80]->position);
        free(board);
        return 1;
    }
}

int main(void) 
{
    int failed = test_piece();
    failed += test_board_91();
    failed += test_board_82();
    failed += test_board_19();

    printf("FAILED : %d\n",failed);
    return failed;
}