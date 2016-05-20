#ifndef _CHESS_H_
#define _CHESS_H_

#include <stdio.h>

#define CHESS_CLASS_NUM 7

#define BOARD_ROW 10
#define BOARD_COL 9

#define MATRIX_SIZE 16

#define USER_BLACK 0x10
#define USER_RED   0x20

#define K_RED       0x10
#define A_RED_I     0x11
#define A_RED_II    0x12
#define B_RED_I     0x13
#define B_RED_II    0x14
#define N_RED_I     0x15
#define N_RED_II    0x16
#define R_RED_I     0x17
#define R_RED_II    0x18
#define C_RED_I     0x19
#define C_RED_II    0x1A
#define P_RED_I     0x1B
#define P_RED_II    0x1C
#define P_RED_III   0x1D
#define P_RED_IV    0x1E
#define P_RED_V     0x1F

#define K_BLACK       0x20
#define A_BLACK_I     0x21
#define A_BLACK_II    0x22
#define B_BLACK_I     0x23
#define B_BLACK_II    0x24
#define N_BLACK_I     0x25
#define N_BLACK_II    0x26
#define R_BLACK_I     0x27
#define R_BLACK_II    0x28
#define C_BLACK_I     0x29
#define C_BLACK_II    0x2A
#define P_BLACK_I     0x2B
#define P_BLACK_II    0x2C
#define P_BLACK_III   0x2D
#define P_BLACK_IV    0x2E
#define P_BLACK_V     0x2F

#define TRUE  +1
#define FALSE -1

#define EMPTY 0


int Side;
const char LegalPosition[ MATRIX_SIZE * MATRIX_SIZE ];
int                Board[ MATRIX_SIZE * MATRIX_SIZE ];

char FEN_string[128];

struct Move
{
    int from;
    int to;
};

struct Move moveOption[128];
int MoveCounter;

void showMatrix(int *matrix, int size);
int isSelfChess(int chess);
int isRed(int chess);
int isBlack(int chess);
char intToChar(int chess);
void boardToFEN();
void clearBoard();
void FENToBoard();
int hasChess(int location);


void moveN(int currentPosition);

#endif
