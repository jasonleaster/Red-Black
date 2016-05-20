#include "chess.h"

void moveN(int currentPosition)
{
    #define POSSIBLE_DIR_N 8
    int direction[POSSIBLE_DIR_N] = {+0x0E, -0x12, -0x21, -0x1F, -0x0E, +0x12, +0x1F, +0x21};
    int check[POSSIBLE_DIR_N]     = {-0x01, -0x01, -0x10, -0x10, +0x01, +0x01, +0x10, +0x10};

    int nextPosition = 0;
    int blocker      = 0;

    int d = 0;
    for(d = 0; d < POSSIBLE_DIR_N; d++)
    {
        nextPosition = currentPosition + direction[d];

        if(LegalPosition[nextPosition] == TRUE)
        {
            blocker = currentPosition + check[d];
            if(hasChess(blocker) == FALSE)
            {
                if(isSelfChess(Board[nextPosition]) == FALSE)
                {
                    saveMove(currentPosition, nextPosition);
                }
            }
        }
    }
}
