// 화면에 글자를 디스플레이할때
#include<curses.h>
#include<iostream>

int Map(){
    char data[2];
    WINDOW *w;
    w= initscr();
    curs_set(0);             // invisible cursor
    using namespace std;
  
    int max_y = LINES-1, max_x = COLS-1;
    char **ptr_matrix = new char * [LINES];

    char mark ='*';

    for(int i = 0; i < LINES; i++)
    {
        ptr_matrix[i] = new char[COLS];
    }

    for (int i = 0; i < LINES; i++)
     for (int j = 0; j < COLS; j++){
        ptr_matrix[i][j] = ' ';
        if(i == 0){
            ptr_matrix[i][j] = mark;
        }
        if(i == 0|| j == 0 || i == LINES-1 || j == COLS-1){
            ptr_matrix[i][j] = mark;
        }
        
    }

    for (int i = 0; i < LINES; i++){
     for (int j = 0; j < COLS; j++){
         data[0] = ptr_matrix[i][j];
         data[1] = 0;
        printw("%c", ptr_matrix[i][j]);
    }
    }

    mvprintw(max_y/2, COLS/2, "Start Game!");

    delete[] ptr_matrix;
    getch();
    endwin();
    return 0;
}
