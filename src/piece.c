#include <stdlib.h>
#include "./piece.h"

piece_t *
init_piece(piece_type_e piece_type)
{
    piece_t *piece;
    piece = calloc(1, sizeof(piece_t));

    piece->type = piece_type;

    return piece;
}

int test(void)
{
    return 0;
}