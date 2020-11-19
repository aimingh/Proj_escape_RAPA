#include <iostream>
#include <curses.h>
#include <cstring>

int Map()
{
    WINDOW *w;
    w= initscr();
    curs_set(0);             // invisible cursor
    using namespace std;

    int max_y = LINES-1, max_x = COLS-1;
    char **pMap = new char * [LINES];
    char mark ='-';
    char *score[9] = " Score: ";


    for (int i = 0; i < LINES; i++){
        pMap[i] = new char[COLS];
    }

    for (int i = 0; i < LINES; i++)
     for (int j = 0; j < COLS; j++){
        pMap[i][j] = ' ';
        if(i == 0){
            pMap[i][j] = mark;
        }
        if(i == 0|| i == LINES-1){
            pMap[i][j] = mark;
        }
    }



    delete[] pMap;
    getch();
    endwin();
    return 0;
}