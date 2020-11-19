#ifndef _GAME_H
#define _GAME_H



// Tayo 구조체 정의하기
typedef struct tagTAYOTYPE
{
    int nX;
    int nY;
    int nWidth;
    int nHeight;
    int nLife;
    char **pShape;
} TAYOTYPE;



int InitTayoObject(void);
TAYOTYPE *GetTayoObject(void);
int GameStart(void);



#endif
