#include <stdio.h>
#include <stdlib.h>
#include "../piece.h"

int testPiece()
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

int main(void) 
{
    int failed = testPiece();
    printf("FAILED : %d\n",failed);
    return failed;
}