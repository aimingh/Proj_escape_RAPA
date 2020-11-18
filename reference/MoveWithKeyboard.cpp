// 화면에 글자를 디스플레이할때
#include<curses.h>
#include<iostream>

#define PLAYER '*'
#define WALL 'W'
#define OPPONENT 'O'
#define E_TRACE ' '

void Keypad();

int main(void){
    WINDOW *w;
    w= initscr();
    curs_set(0);             // invisible cursor
    using namespace std;
    
    // FUNCS
    Keypad();
    
    // END MAIN 
    endwin();
    return 0;
}

void Keypad(){
    keypad(stdscr, TRUE); timeout(30); // control game speed
    int y = LINES-1, x=COLS-COLS, move_x = 0, move_y = 0; // start main
    int ch ='y';   //define integer for compare with define
    while((ch !='q') && (ch!='Q')){
        mvaddch(++move_y, ++move_x, OPPONENT); //auto moving
        mvaddch(y,x,PLAYER); mvaddch(10,5,WALL); mvaddch(11,5, OPPONENT);
        ch = getch();
        switch(ch) {
            case KEY_UP:
            case 'W':              y=y-1; break;
            case KEY_DOWN:
            case 'S':              y=y+1; break;         
            case KEY_LEFT:
            case 'A':              x=x-1; break;         
            case KEY_RIGHT:
            case 'D':              x=x+1; mvaddch(y, x-1, E_TRACE); break;        
        }
    }  //end main
}