#include <stdio.h>
#include <stdlib.h>
#include "../src/piece.h"
#include "../src/board.h"

int test_piece_type()
{
    piece_type_e ptype = GYOKU;
    piece_owner_e powner = FIRST_PLAYER;
    piece_t *piece = init_piece(ptype, powner);
    
    if (piece->type == 1) {
        free(piece);
        return 0;
    } else {
        free(piece);
        printf("failed in test_piece_type : expect 1 but got %d\n",piece->type);
        return 1;
    }
}

int test_piece_owner1()
{
    piece_type_e ptype = GYOKU;
    piece_owner_e powner = FIRST_PLAYER;
    piece_t *piece = init_piece(ptype, powner);
    
    if (piece->owner == 1) {
        free(piece);
        return 0;
    } else {
        free(piece);
        printf("failed in test_piece_owner1 : expect 1 but got %d\n",piece->owner);
        return 1;
    }
}

int test_piece_owner2()
{
    piece_type_e ptype = GYOKU;
    piece_owner_e powner = SECOND_PLAYER;
    piece_t *piece = init_piece(ptype, powner);
    
    if (piece->owner == 2) {
        free(piece);
        return 0;
    } else {
        free(piece);
        printf("failed in test_piece_owner : expect 2 but got %d\n",piece->owner);
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

int test_board_91_piece_type()
{
    board_t *board = init_board();
    if (board->square[0]->piece.type == KYOU) {
        free(board);
        return 0;
    } else {
        printf("failed in test_board_91_piece_type : expect 7 but got %d\n",board->square[0]->piece.type);
        free(board);
        return 1;
    }
}

int test_board_go_forward()
{
    board_t *board = init_board();
    board_go_forward(board, 8, 17);
    if (board->square[17]->piece.type == KYOU) {
        if (board->square[17]->piece.owner == SECOND_PLAYER) {
            free(board);
            return 0;
        } else {
            printf("failed in test_board_go_forward : expect owner is  2 but got %d\n", board->square[17]->piece.owner);
            free(board);
            return 1;
        }
    } else {
        printf("failed in test_board_go_forward : expect type is 7 but got %d\n", board->square[17]->piece.type);
        free(board);
        return 1;
    }
}

int board_display()
{
    board_t *board = init_board();
    for (int i = 0; i < 9; i++) {
        printf(" | ");
        for (int j=0; j < 9; j++) {
            printf("%d | ",board->square[i * 9 + j]->piece.type);
        }
        putchar('\n');
    }
    putchar('\n');
    free(board);
    return 0;
}

int main(void) 
{
    int failed = test_piece_type();
    failed += test_piece_owner1();
    failed += test_piece_owner2();
    failed += test_board_91_position();
    failed += test_board_82_position();
    failed += test_board_19_position();
    failed += test_board_93_players_base();
    failed += test_board_55_players_base();
    failed += test_board_97_players_base();
    failed += test_board_91_piece_type();
    failed += test_board_go_forward();
    board_display();

    printf("FAILED : %d\n",failed);
    return failed;
}