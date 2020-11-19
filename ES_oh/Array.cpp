#include <iostream>

#include "Array.h"



/*
 * 함 수 명 : CreateArray
 * 설    명 : 2차원 동적 메모리 할당 (nRow x nCol)
 */
void CreateArray(char ***pData, char nRow, char nCol)
{
        int i = 0;
        char **p = NULL;


        p = new char *[nRow];
        for (i = 0; i < nRow; i++)
        {
                p[i] = new char[nCol];
        }

        *pData = p;
}

/*
 * 함 수 명 : DeleteArray
 * 설    명 : 동적 메모리 해제
 */
void DeleteArray(char ***pData, int nRow)
{
        int i = 0;

        char **p = 0;



        p = *pData;

        for (i = 0; i < nRow; i++)
        {
                delete [] p[i];
                p[i] = NULL;
        }

        delete [] p;
        p = NULL;

        *pData = p;
}
