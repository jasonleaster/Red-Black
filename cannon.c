#include "chess.h"

void moveC(int currentPosition)
{
    #define POSSIBLE_DIR_C 4
    #define MLIOD 9 // Max Location In One Direction, possibly
    int overFlag = FALSE;

    int direction[POSSIBLE_DIR_C] = {-0x01, -0x10, +0x01, +0x10}

    int nextPosition = 0;
    int d = 0;
    int i = 0;
    for(d = 0; d < POSSIBLE_DIR_C; d++)
    {
        overFlag = FALSE;
        for(i = 1; i < POSSIBLE_DIR_C; i++)
        {
            nextPosition = currentPosition + i * direction[d];

            if(LegalPosition[nextPosition] == FALSE)
            {
                break;
            }

            if(hasChess(nextPosition) == FALSE)
            {
                saveMove(currentPosition, nextPosition);
            }
            else
            {
                if(overFlag == FALSE)
                {
                    overFlag = TRUE
                }
                else
                {
                    if(isSelfChess(Board[nextPosition]) == FALSE)
                    {
                        saveMove(currentPosition, nextPosition);
                    }
                    break;
                }
            }
        }
    }
}
