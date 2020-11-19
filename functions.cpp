#include <curses.h>
#include <string>
using namespace std;
#define E_TRACE ' '

struct Player
{
    int x, y, life = 3; // current location and survival life
    static const int shape_size_y = 3, shape_size_x = 11;
    void appear(const int &move_y, const int &move_x){
        mvaddstr(move_y-this->shape_size_y+1, move_x," --------- ");    //Tayo bus
        mvaddstr(move_y-this->shape_size_y+2, move_x,"|      |OO|");
        mvaddstr(move_y-this->shape_size_y+3, move_x," --@--@--- ");
    }
};

struct obj_RAPA
{
    int x=COLS - 1, y = LINES - 1; // current location and survival life
    static const int shape_size_y = 3, shape_size_x = 10;
    void appear(const int &move_y, const int &move_x){
        mvaddstr(move_y-this->shape_size_y+1, move_x," -------- ");    // enemy python
        mvaddstr(move_y-this->shape_size_y+2, move_x,"| Python |");
        mvaddstr(move_y-this->shape_size_y+3, move_x," -------- ");
    }
};

void game_start();  // main game start
void map_init(char **, int, int);      // init map start values
void display_map(char **, int, int);   // display map
int is_move_ok(int, int);               // check obstacle to direction of moving
struct Player move2direction(int ch, struct Player player);                    // move to direction
struct Player gravityOfPlayer(int, struct Player);
struct obj_RAPA moveObj(int, struct obj_RAPA);

void game_start(){
    WINDOW *w;  // init curses
	w = initscr();		
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

int is_move_ok(int y, int x){   // 아래 충돌은 문제 없음 위 충돌 및 윈도우 밖으로 안나가도록 출동 판정 업그레이드 필요
    int compare_ch;
    compare_ch = mvinch(y,x); // 주어진 위치 문자 return
    return !((compare_ch=='*' || y >LINES || y<3 || x > COLS- 70 || x < 0));
}

struct Player move2direction(int ch, struct Player player){
    switch (ch)    {
        case KEY_UP:
            if (is_move_ok(player.y - player.shape_size_y - 6,player.x)){player.y = player.y - 5;}; break;
        case KEY_DOWN:
            if (is_move_ok(player.y + 1,player.x)){player.y = player.y + 1;}; break;
        case KEY_LEFT:
            if (is_move_ok(player.y,player.x - 1)){player.x = player.x - 1;}; break;
        case KEY_RIGHT:
            if (is_move_ok(player.y,player.x + player.shape_size_y + 1)){player.x = player.x + 1;}; break;
    }
    return player;
}

struct Player gravityOfPlayer(int counter, struct Player player){
    int maxtime = 10;
    if(counter%maxtime==maxtime-1){
        if (is_move_ok(player.y + 1,player.x)){player.y = player.y + 1;}
    }
    return player;
}

struct obj_RAPA moveObj(int counter, struct obj_RAPA rapa){
    int maxtime = 10;
    if(counter%maxtime==maxtime-1){
        rapa.x = rapa.x - 1;
    }
    return rapa;
}

struct obj_RAPA generateObjRAPA(int counter){
    int maxtime = 6;
    if(counter%maxtime==maxtime-1){
        struct obj_RAPA rapa;
        return rapa;
    }
}