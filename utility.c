#include "chess.h"

void showMatrix(int *matrix, int size)
{
    int len = size* size;

    int i = 0;

    for(i = 0; i < size * size; i++)
    {
        if(i % size == 0)
        {
            printf("\n\n");
        }

        if(matrix[i] == 0)
        {
            printf("0\t");
        }
        else
        {
            printf("%c\t", intToChar(matrix[i]));
        }
    }
    printf("\n\n");
}

int hasChess(int location)
{
    if(Board[location] == EMPTY)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

int isSelfChess(int chess)
{
    if (chess & (Side << 4 + 16) == 0x1)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int isRed(int chess)
{
    if(chess & K_RED)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int isBlack(int chess)
{
    if(chess & K_BLACK)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

