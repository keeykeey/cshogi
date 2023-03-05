#include <stdio.h>
#include <stdlib.h>
#include "./board.h"
#include "./piece.h"

board_t *
init_board()
{
    /*
     * ELEMENT OF board_t ARRAY
     * board_t : is an array whitch has 81 element
     *  0  1  2  3  4  5  6  7  8  
     *  9 10 11 12 13 14 15 16 17 
     * 18 19 20 21 22 23 24 25 26 
     * 27 28 29 30 31 32 33 34 35 
     * 36 37 38 39 40 41 42 43 44 
     * 45 46 47 48 49 50 51 52 53 
     * 54 55 56 57 58 59 60 61 62 
     * 63 64 65 66 67 68 69 70 71 
     * 72 73 74 75 76 77 78 79 80 
     *
     * NAME of each square in the board
     * the number to represent board position in each element is like below
     * 91 81 71 61 51 41 31 21 11
     * 92 82 72 62 52 42 32 22 22
     * 93 83 73 63 53 43 33 23 13
     * 94 84 74 64 54 44 34 24 14
     * 95 85 75 65 55 45 35 25 15
     * 96 86 76 66 56 46 36 26 16
     * 97 87 77 67 57 47 37 27 17
     * 98 88 78 68 58 48 38 28 18
     * 99 89 79 69 59 49 39 29 19
     */
    board_t *board;
    board = calloc(1, sizeof(board_t));

    square_t *sq;
    sq = calloc(81,sizeof(square_t));

    for (int h = 1; h <= 9; h++) {
        int w = 9;
        while(w >= 1) {
            // set position
            sq->position  = w * 10 + h;
            if (h == 1) {
                sq->top_left  = CSHOGI_OUTOF_BOARD;
                sq->top       = CSHOGI_OUTOF_BOARD;
                sq->top_right = CSHOGI_OUTOF_BOARD;
            } else {
                sq->top_left  = (sq->position % 9 != 0) ? sq->position - 10 : CSHOGI_OUTOF_BOARD;
                sq->top       = (sq->position >= 10)    ? sq->position -  9 : CSHOGI_OUTOF_BOARD;
                sq->top_right = (sq->position % 9 != 8) ? sq->position -  8 : CSHOGI_OUTOF_BOARD;
            }
            sq->left  = (sq->position % 9 != 1) ? sq->position - 1 : CSHOGI_OUTOF_BOARD;
            sq->right = (sq->position % 9 != 0) ? sq->position + 1 : CSHOGI_OUTOF_BOARD;
            if (h == 9) {
                sq->bottom_left  = CSHOGI_OUTOF_BOARD;   
                sq->bottom       = CSHOGI_OUTOF_BOARD;
                sq->bottom_right = CSHOGI_OUTOF_BOARD;
            } else {
                sq->bottom_left  = (sq->position % 9 != 0) ? sq->position +  8 : CSHOGI_OUTOF_BOARD;
                sq->bottom       = (sq->position <= 72)    ? sq->position +  9 : CSHOGI_OUTOF_BOARD;
                sq->bottom_right = (sq->position % 9 != 8) ? sq->position + 10 : CSHOGI_OUTOF_BOARD;
            }

            // set platers base
            if (h <= 3) {
                sq->is_first_players_base = false;
                sq->is_second_players_base = true;
            } else if (h >= 7) {
                sq->is_first_players_base = true;
                sq->is_second_players_base = false;
            } else {
                sq->is_first_players_base = false;
                sq->is_second_players_base = false;
            }

            // set piece_t
            if (h == 1 || h == 9) {
                switch (w) {
                    case 9:
                        sq->piece.type = KYOU;
                        break;
                    case 8:
                        sq->piece.type = KEI;
                        break;
                    case 7:
                        sq->piece.type = GIN;
                        break;
                    case 6:
                        sq->piece.type = KIN;
                        break;
                    case 5:
                        sq->piece.type = GYOKU;
                        break;
                    case 4:
                        sq->piece.type = KIN;
                        break;
                    case 3:
                        sq->piece.type = GIN;
                        break;
                    case 2:
                        sq->piece.type = KEI;
                        break;
                    case 1:
                        sq->piece.type = KYOU;
                        break;
                    default:
                        sq->piece.type = EMPTY;
                        break;
                }
            } else if (h == 2) {
                switch (w) {
                    case 8:
                        sq->piece.type = HISHA;
                        break;
                    case 2:
                        sq->piece.type = KAKU;
                        break;
                    default:
                        sq->piece.type = EMPTY;
                        break;
                }
            } else if (h == 3 || h == 7) {
                sq->piece.type = FU;
            } else if (h == 8) {
                switch (w) {
                    case 8:
                        sq->piece.type = KAKU;
                        break;
                    case 2:
                        sq->piece.type = HISHA;
                        break;
                    default:
                        sq->piece.type = EMPTY;
                        break;
                }
            } else {
                sq->piece.type = EMPTY;
            }

            board->square[(h-1)*9 + 9 - w] = sq;
            sq++;
            w--;
        }
    }

    return board;
}