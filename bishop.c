#include "chess.h"

const char LegalPositionOfB[ MATRIX_SIZE * MATRIX_SIZE ] = 
{
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, +1, -1, -1, -1, +1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, +1, -1, -1, -1, +1, -1, -1, -1, +1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, +1, -1, -1, -1, +1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, +1, -1, -1, -1, +1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, +1, -1, -1, -1, +1, -1, -1, -1, +1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, +1, -1, -1, -1, +1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
};

int moveB(int currentPosition)
{
    #define POSSIBLE_DIR_B 4
    int direction[POSSIBLE_DIR_B] = {-0x22, -0x1E, +0x22, +0x1E};
    int check[POSSIBLE_DIR_B] = {-0x11, -0x0F, +0x11, +0x0F};

    int nextPosition = 0;
    int blocker = 0;

    int d = 0;
    for(d = 0; d < POSSIBLE_DIR_B; d++)
    {
        nextPosition = currentPosition + direction[d];

        if(LegalPositionOfB[nextPosition] == TRUE)
        {
            blocker = currentPosition + check[d];

            if(Board[blocker] == EMPTY)
            {
                if(isSelfChess(Board[nextPosition]) == FALSE)
                {
                    saveMove(currentPosition, nextPosition);
                }
            }
        }
    }
}
