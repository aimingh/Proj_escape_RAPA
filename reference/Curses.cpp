#include<curses.h>
int main(){
    initscr();
    printw("Hello Ncurse!");
    refresh();    // end main
    getch();
    endwin();
    return 0;
}