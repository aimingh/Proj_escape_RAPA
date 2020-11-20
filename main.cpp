#include <iostream>
#include <string>
#include <curses.h>
#include "Characters.hpp"
using namespace std;

#define E_TRACE ' '

int is_move_okay(int y, int x);

int main(void){
    WINDOW *w;
    w = initscr();
    curs_set(0);

    keypad(stdscr, TRUE); timeout(30); //control game speed
    int y = LINES-1, x = COLS-COLS, move_x = 0, move_y = 0; //start main
    int ch = 'y'; //define integer for compare with define, 정수 선언?

    hero::tayo hero;

	enemy::python py;
	enemy::css css;
	enemy::cpp cpp;
	enemy::html html;

    while((ch!='q') && (ch !='Q')){
        hero.appear(y-2,x);

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