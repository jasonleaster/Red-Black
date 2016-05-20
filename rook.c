#include "chess.h"

void moveR(int currentPosition)
{
    #define POSSIBLE_DIR_R 4
    #define MLIOD 9 // Max Location In One Direction, possibly
    int direction[POSSIBLE_DIR_R] = {-0x01, -0x10, +0x01, +0x10};

    int nextPosition = 0;

    int d = 0;
    int i = 0;
    for(d = 0; d < POSSIBLE_DIR_R; d++)
    {
        for(i = 1; i <= MLIOD; i++ )
        {
            nextPosition = currentPosition + i * direction[d];

            if(LegalPosition[nextPosition] == FALSE)
            {
                break;
            }

            if(Board[nextPosition] == EMPTY)
            {
                saveMove(currentPosition, nextPosition);
            }
            else if (isSelfChess(Board[nextPosition]) == TRUE)
            {
                break;
            }
            else
            {   // there is a opponent
                saveMove(p, n);
                break;
            }
        }
    }
}
