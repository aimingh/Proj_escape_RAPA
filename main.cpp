#include <curses.h>
#include <string>
#include "functions.hpp"




int main(){
    // init curses
    WINDOW *w;
	w = initscr();		
    curs_set(0);    //invisible cursor
	keypad(stdscr, TRUE);
    int ch = 'y';
	timeout(30);

	int max_y = LINES, max_x = COLS-70;                  // define size of main window

	char **map = new char*[max_y];                          // define map
    for (int i=0; i<max_y; i++){
        map[i] = new char[max_x];
    }
	map_init(map, max_y, max_x);
	Player player;  // define player
    player.x = 1; player.y = LINES -2;  // player start location

    //************start main************
	while((ch != 'q') && (ch != 'Q')){
		display_map(map, max_y, max_x);
        player.appear(player.y,player.x);
        ch = getch();
        switch (ch)
        {
            case KEY_UP:
                if (is_move_ok(player.y - 1,player.x)){player.y = player.y - 1;}; mvaddch(player.y + 1, player.x, E_TRACE); break;
            case KEY_DOWN:
                if (is_move_ok(player.y + 1,player.x)){player.y = player.y + 1;}; mvaddch(player.y - 1, player.x, E_TRACE); break;
            case KEY_LEFT:
                if (is_move_ok(player.y,player.x - 1)){player.x = player.x - 1;}; mvaddch(player.y, player.x + 1, E_TRACE); break;
            case KEY_RIGHT:
                if (is_move_ok(player.y,player.x + 1)){player.x = player.x + 1;}; mvaddch(player.y, player.x - 1, E_TRACE); break;
        }
    }
    //************end main************
	endwin();
	return 0;
}