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

int test_board_91_position()
{
    board_t *board = init_board();
    
    if (board->square[0]->position == 91) {
        free(board);
        return 0;
    } else {
        free(board);
        printf("failed in test_board_91_position : expect 91 but got %d\n",board->square[0]->position);
        return 1;
    }
}

int test_board_82_position()
{
    board_t *board = init_board();
    
    if (board->square[10]->position == 82) {
        free(board);
        return 0;
    } else {
        printf("failed in test_board_82_position : expect 82 but got %d\n",board->square[10]->position);
        free(board);
        return 1;
    }
}

int test_board_19_position()
{
    board_t *board = init_board();
    
    if (board->square[80]->position == 19) {
        free(board);
        return 0;
    } else {
        printf("failed in test_board_19_position : expect 19 but got %d\n",board->square[80]->position);
        free(board);
        return 1;
    }
}

int test_board_93_players_base()
{
    board_t *board = init_board();
    if (board->square[18]->is_first_players_base == false) {
        if (board->square[18]->is_second_players_base == true) {
            free(board);
            return 0;
        } else {
            printf("failed in test_board_93_platers_base : expect is_second_players_base is true, but got false\n");
            free(board);
            return 1;
        }
    } else {
        printf("failed in test_board_93_platers_base : expect is_first_players_base is false, but got true\n");
        free(board);
        return 1;
    }
}

int test_board_55_players_base()
{
    board_t *board = init_board();
    if (board->square[40]->is_first_players_base == false) {
        if (board->square[40]->is_second_players_base == false) {
            free(board);
            return 0;
        } else {
            printf("failed in test_board_55_platers_base : expect is_second_players_base is false, but got true\n");
            free(board);
            return 1;
        }
    } else {
        printf("failed in test_board_55_platers_base : expect is_first_players_base is false, but got true\n");
        free(board);
        return 1;
    }
}

int test_board_97_players_base()
{
    board_t *board = init_board();
    if (board->square[54]->is_first_players_base == true) {
        if (board->square[54]->is_second_players_base == false) {
            free(board);
            return 0;
        } else {
            printf("failed in test_board_97_platers_base : expect is_second_players_base is false, but got true\n");
            free(board);
            return 1;
        }
    } else {
        printf("failed in test_board_97_platers_base : expect is_first_players_base is false, but got true\n");
        free(board);
        return 1;
    }
}

int main(void) 
{
    int failed = test_piece();
    failed += test_board_91_position();
    failed += test_board_82_position();
    failed += test_board_19_position();
    failed += test_board_93_players_base();
    failed += test_board_55_players_base();
    failed += test_board_97_players_base();

    printf("FAILED : %d\n",failed);
    return failed;
}