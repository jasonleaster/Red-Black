#include "chess.h"

char intToChar(int chess)
{
    if(isRed(chess) == TRUE)
    {
        switch(chess)
        {
            case K_RED:     return 'K';
            case A_RED_I:
            case A_RED_II:  return 'A';
            case B_RED_I:
            case B_RED_II:  return 'B';
            case N_RED_I:
            case N_RED_II:  return 'N';
            case R_RED_I:
            case R_RED_II:  return 'R';
            case C_RED_I:
            case C_RED_II:  return 'C';
            case P_RED_I:
            case P_RED_II:
            case P_RED_III:
            case P_RED_IV:
            case P_RED_V:   return 'P';

            default:
                            return FALSE;
        }
    }
    else
    {
        switch(chess)
        {
            case K_BLACK:     return 'k';
            case A_BLACK_I:
            case A_BLACK_II:  return 'a';
            case B_BLACK_I:
            case B_BLACK_II:  return 'b';
            case N_BLACK_I:
            case N_BLACK_II:  return 'n';
            case R_BLACK_I:
            case R_BLACK_II:  return 'r';
            case C_BLACK_I:
            case C_BLACK_II:  return 'c';
            case P_BLACK_I:
            case P_BLACK_II:
            case P_BLACK_III:
            case P_BLACK_IV:
            case P_BLACK_V:   return 'p';

            default:
                            return FALSE;
        }

    }
}


void boardToFEN()
{
    int row = 0;
    int row_start = (MATRIX_SIZE - BOARD_ROW)/2;
    int row_end   = row_start + BOARD_ROW;

    int col = 0;
    int col_start = (MATRIX_SIZE - BOARD_COL)/2;
    int col_end   = col_start + BOARD_COL;

    int chess;
    int blank_counter = 0;

    int FEN_idx = 0;
    for (row = row_start; row < row_end; row++)
    {
        blank_counter = 0;
        for (col = col_start; col < col_end; col++)
        {
            chess = Board[row * MATRIX_SIZE + col];
            if(chess == 0)
            {
                blank_counter++;
            }
            else
            {
                if(blank_counter > 0)
                {
                    FEN_string[FEN_idx] = blank_counter + '0';
                    FEN_idx++;
                    blank_counter = 0;
                }
                FEN_string[FEN_idx] = intToChar(chess);
                FEN_idx++;
            }
        }

        if(blank_counter > 0)
        {
            FEN_string[FEN_idx] = blank_counter + '0';
            FEN_idx++;
            blank_counter = 0;
        }

        if(row != row_end-1)
        {
            FEN_string[FEN_idx] = '/';
            FEN_idx++;
        }
    }

    FEN_string[FEN_idx] = ' ';
    FEN_idx++;

    if(Side = USER_RED)
    {
        FEN_string[FEN_idx] = 'r';
    }
    else
    {
        FEN_string[FEN_idx] = 'b';
    }

    FEN_idx++;

}

void clearBoard()
{
    int i = 0;
    for(i = 0; i < MATRIX_SIZE * MATRIX_SIZE; i++)
    {
        Board[i] = 0;
    }
}

int chessRed[CHESS_CLASS_NUM];
int chessBlack[CHESS_CLASS_NUM];

int charToChessIdx(char ch)
{
    switch(ch)
    {
        case 'k':
        case 'K': return 0;
        case 'a':
        case 'A': return 1;
        case 'b':
        case 'B': return 2;
        case 'n':
        case 'N': return 3;
        case 'r':
        case 'R': return 4;
        case 'c':
        case 'C': return 5;
        case 'p':
        case 'P': return 6;

        default:
                  return FALSE;
    }
}


void FENToBoard()
{

    clearBoard();

    int i = 0;
    int row = (MATRIX_SIZE - BOARD_ROW)/2;
    int col = (MATRIX_SIZE - BOARD_COL)/2;

    int initChessRed  [CHESS_CLASS_NUM] = {K_RED,   A_RED_I,    B_RED_I,    N_RED_I,    R_RED_I,    C_RED_I,    P_RED_I};
    int initChessBlack[CHESS_CLASS_NUM] = {K_BLACK, A_BLACK_I,  B_BLACK_I,  N_BLACK_I,  R_BLACK_I,  C_BLACK_I,  P_BLACK_I};

    int idx = 0;
    for(i = 0; FEN_string[i] != ' ' && FEN_string[i] != '\0'; i++)
    {
        if(FEN_string[i] == '/')
        {
            row++;
            col = (MATRIX_SIZE - BOARD_COL)/2;
        }
        else if(FEN_string[i] >= '1' && FEN_string[i] <= '9')
        {
            col += FEN_string[i] - '0';
        }
        else if(FEN_string[i] >= 'A' && FEN_string[i] <= 'Z') // red user represented as capital letter
        {
            idx = row * MATRIX_SIZE + col;
            Board[idx] = initChessRed[charToChessIdx( FEN_string[i] )];
            initChessRed[charToChessIdx( FEN_string[i] )]++;
            col++;
        }
        else if(FEN_string[i] >= 'a' && FEN_string[i] <= 'z')// black user represented as lowercase
        {
            idx = row * MATRIX_SIZE + col;
            Board[idx] = initChessBlack[charToChessIdx( FEN_string[i] )];
            initChessBlack[charToChessIdx( FEN_string[i] )]++;
            col++;
        }
    }

    if(FEN_string[i] == 'r')
    {
        Side = USER_RED;
    }
    else
    {
        Side = USER_BLACK;
    }

}

