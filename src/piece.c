#include <stdlib.h>
#include "./piece.h"

piece_t *
init_piece(piece_type_e ptype, piece_owner_e powner)
{
    piece_t *piece;
    piece = calloc(1, sizeof(piece_t));

    piece->type = ptype;
    piece->owner = powner;

    return piece;
}