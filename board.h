#ifndef BOARD_H
#define BOARD_H

#include <stdbool.h>
#include "./conf.h"
#include "./piece.h"

// MACRO

// TYPE
typedef struct square_s square_t;
struct  square_s {
    cshogi_int_t    position;
    piece_t        *piece;
    square_t       *top_left;
    square_t       *top;
    square_t       *top_right;
    square_t       *left;
    square_t       *right;
    square_t       *bottom_left;
    square_t       *bottom;
    square_t       *bottom_right;
    bool            is_first_players_base;
    bool            is_second_players_base;
};

typedef struct {
    square_t        *square[81];
} board_t;

// PROTOTYPE
square_t   *init_square(void);
board_t    *init_board(void);

#endif