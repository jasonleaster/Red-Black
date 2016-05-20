#include "chess.h"

void initGenMoveOption()
{
    MoveCounter = 0;
}

void saveMove(int from, int to)
{
    moveOption[MoveCounter].from = from;
    moveOption[MoveCounter].to   = to;
    MoveCounter++;
}

void GenAllMove()
{
    int row = 0;
    int row_start = (MATRIX_SIZE - BOARD_ROW)/2;
    int row_end   = row_start + BOARD_ROW;

    int col = 0;
    int col_start = (MATRIX_SIZE - BOARD_COL)/2;
    int col_end   = col_start + BOARD_COL;

    int idx = 0;
    for(row = row_start; row < row_end; row++)
    {
        for(col = col_start; col < col_end; col++)
        {
            idx = row * MATRIX_SIZE + col;

        }
    }


}
