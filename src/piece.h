#ifndef PIECE_H
#define PIECE_H

// MACRO

// TYPE
typedef enum {
    EMPYT,
    GYOKU,
    HISHA,
    KAKU,
    KIN,
    GIN,
    KEI,
    KYOU,
    FU,
} piece_type_e;

typedef enum {
    FIRST_PLAYER = 1,
    SECOND_PLAYER,
} piece_owner_e;

typedef struct {
    piece_type_e       type;
    piece_owner_e      owner;
} piece_t;

// PROTOTYPE
piece_t *init_piece(piece_type_e piece_type, piece_owner_e piece_owner);
int test(void);

#endif