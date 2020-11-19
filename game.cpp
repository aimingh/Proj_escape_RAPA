#include <iostream>
#include <curses.h>
#include "common.hpp"
using namespace std;

void game_start(){
    // WINDOW *w;  // init curses
	// w = initscr();		
	initscr();		
    curs_set(0);    //invisible cursor
    timeout(30);
	keypad(stdscr, TRUE);
    int ch = 'y';
	
	int max_y = LINES, max_x = COLS-70; // define size of main window
	char **map = new char*[max_y];  // define map
    for (int i=0; i<max_y; i++){
        map[i] = new char[max_x];
    }
	map_init(map, max_y, max_x);
	Player player;  // define player
    player.x = 1; player.y = LINES - 2;  // player start location

    struct obj_RAPA rapa;
    rapa.x = max_x-rapa.shape_size_x-1; rapa.y = LINES - 2;

    int timeCounter = 0;    //time counter

	while((ch != 'q') && (ch != 'Q')){

		display_map(map, max_y, max_x);
        player.appear(player.y,player.x);
        if(timeCounter>10){   //test generate rapa
            rapa.appear(rapa.y, rapa.x);
            rapa = moveObj(timeCounter, rapa);
        }
        string timestring = "time: " + to_string(timeCounter);  //show time
        mvaddstr(1, 1, timestring.c_str()); 
        ch = getch();
        player = move2direction(ch, player);
        player = gravityOfPlayer(timeCounter, player);
        timeCounter++;
    }
	endwin();
}

// init map start values
void map_init(char **map, int max_y, int max_x){
    for(int i=0; i<max_y; i++){
        for (int j=0; j<max_x; j++){
            map[i][j] = ' ';
            if(i==0 || i==max_y-1 || i==2){
                map[i][j] = '*';
            }
        }
    }
}

// display map
void display_map(char **map, int max_y, int max_x){
    for(int i=0; i<max_y; i++){
        for (int j=0; j<max_x; j++){
            mvaddch(i,j,map[i][j]);
        }
    }
}