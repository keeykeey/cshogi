#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>
#include "./conf.h"
#include "./piece.h"

// MACRO
#define CSHOGI_OUTOF_BOARD -1

// TYPE
typedef struct square_s square_t;
struct  square_s {
    cshogi_int_t       position;
    piece_t            piece;
    cshogi_int_t       top_left;
    cshogi_int_t       top;
    cshogi_int_t       top_right;
    cshogi_int_t       left;
    cshogi_int_t       right;
    cshogi_int_t       bottom_left;
    cshogi_int_t       bottom;
    cshogi_int_t       bottom_right;
    bool               is_first_players_base;
    bool               is_second_players_base;
};

typedef struct {
    square_t        *square[81];
} board_t;

// PROTOTYPE
square_t   *init_square(void);
board_t    *init_board(void);
void        board_go_forward(board_t *board, cshogi_int_t board_el_from, cshogi_int_t board_el_to);

#endif