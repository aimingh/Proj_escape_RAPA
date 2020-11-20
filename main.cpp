#include <iostream>
#include <string>
#include <curses.h>
#include "Common.hpp"
using namespace std;

#define E_TRACE ' '

int is_move_okay(int y, int x);

int main(void){
    WINDOW *w;
    w = initscr();
    curs_set(0);
    keypad(stdscr, TRUE); timeout(30); //control game speed
    int y = LINES-1, x = COLS-COLS, move_x = 0, move_y = 0; //start main
    int ch = 'y'; //keyboard init, can define any key without using key(in this case:q and Q)

    struct tayo tayo;
    struct python py;
    struct css css;
    struct cpp cpp;
    struct html html;

    while((ch!='q') && (ch !='Q')){
        tayo.appear(y-2,x);
		py.appear(20,50);
		css.appear(30,40);
		cpp.appear(10,20);
		html.appear(30,60);

        ch = getch();
        switch (ch){
            case KEY_UP: if(is_move_okay(y-1,x)){y = y - 1;};break;
            case KEY_DOWN: if(is_move_okay(y+1,x)){y = y + 1;}; break;
            case KEY_LEFT: if(is_move_okay(y,x-1)){x = x - 1;}; break;
            case KEY_RIGHT: x = x + 1; mvaddch(y-2,x-1,E_TRACE); mvaddch(y-1,x-1,E_TRACE); mvaddch(y,x-1,E_TRACE); break;
        }
    }
    endwin();
    return 0;
}

int is_move_okay(int y, int x){
    int campare_ch;
    campare_ch = mvinch(y,x); //주어진 위치 문자 return
    return ((campare_ch != 'W'));
}