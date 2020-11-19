#include <curses.h>
#define E_TRACE ' '

struct Player
{
    int x, y, life = 3;
    static const int shape_size_y = 2, shape_size_x = 5;
    void appear(const int &move_y, const int &move_x){
        mvaddstr(move_y-this->shape_size_y+1, move_x,"*****");
        mvaddstr(move_y-this->shape_size_y+2, move_x,"*@*@*");
    }
};

void game_start();
void map_init(char **, int, int);      // init map start values
void display_map(char **, int, int);   // display map
int is_move_ok(int, int);               // check obstacle to direction of moving
struct Player move2direction(int ch, struct Player player);                    // move to direction

void game_start(){
    WINDOW *w;  // init curses
	w = initscr();		
    curs_set(0);    //invisible cursor
	keypad(stdscr, TRUE);
    int ch = 'y';
	timeout(30);
	int max_y = LINES, max_x = COLS-70; // define size of main window
	char **map = new char*[max_y];  // define map
    for (int i=0; i<max_y; i++){
        map[i] = new char[max_x];
    }
	map_init(map, max_y, max_x);
	Player player;  // define player
    player.x = 1; player.y = LINES -2;  // player start location

	while((ch != 'q') && (ch != 'Q')){
		display_map(map, max_y, max_x);
        player.appear(player.y,player.x);
        ch = getch();
        player = move2direction(ch, player);
    }
	endwin();
}

// init map start values
void map_init(char **map, int max_y, int max_x){
    for(int i=0; i<max_y; i++){
        for (int j=0; j<max_x; j++){
            map[i][j] = '~';
            if(i==0 || i==max_y-1 ||j==0 || j==max_x-1){
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

int is_move_ok(int y, int x){
    int compare_ch;
    compare_ch = mvinch(y,x); // 주어진 위치 문자 return
    return !((compare_ch=='W'));
}

struct Player move2direction(int ch, struct Player player){
    switch (ch)    {
        case KEY_UP:
            if (is_move_ok(player.y - 1,player.x)){player.y = player.y - 1;}; mvaddch(player.y + 1, player.x, E_TRACE); break;
        case KEY_DOWN:
            if (is_move_ok(player.y + 1,player.x)){player.y = player.y + 1;}; mvaddch(player.y - 1, player.x, E_TRACE); break;
        case KEY_LEFT:
            if (is_move_ok(player.y,player.x - 1)){player.x = player.x - 1;}; mvaddch(player.y, player.x + 1, E_TRACE); break;
        case KEY_RIGHT:
            if (is_move_ok(player.y,player.x + 1)){player.x = player.x + 1;}; mvaddch(player.y, player.x - 1, E_TRACE); break;
    }
    return player;
}