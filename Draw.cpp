#include <iostream>
#include <curses.h>

#include "common.h"



/*
 * 함 수 명 : FillCharacter
 * 설    명 : 특정 영역을 지정한 문자로 채운다.
 */
int FillCharacter(char ch, int nX, int nY, int nWidth, int nHeight)
{
    int i = 0;
    int j = 0;
    int nRet = 1;



    for (i = 0; i < nHeight; i++)
    {
        for (j = 0; j < nWidth; j++)
        {
            mvaddch(i + nY, j + nX, ch);
        }
    }

    return nRet;
}



/*
 * 함 수 명 : DrawObject
 * 설    명 : 메모리에 저장된 내용을 출력한다.
 */
int DrawObject(char **p, int nX, int nY, int nWidth, int nHeight)
{
    int i = 0;
    int j = 0;

    int nRet = 1;



    for (i = 0; i < nHeight; i++)
    {
        for (j = 0; j < nWidth; j++)
        {
            mvaddch(i + nY, j + nX, p[i][j]);
        }
    }

    return nRet;
}
