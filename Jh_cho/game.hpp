#include <curses.h>

// player에 대한 structure
struct Player{
    int x, y, life = 3; // current location and survival life
    int f1;
    static const int shape_size_y = 3, shape_size_x = 11;
    void appear(const int &move_y, const int &move_x){  // 플레이어 출력
        mvaddstr(move_y-this->shape_size_y+1, move_x," --------- ");    //Tayo bus
        mvaddstr(move_y-this->shape_size_y+2, move_x,"|      |OO|");
        mvaddstr(move_y-this->shape_size_y+3, move_x," --@--@--- ");
    }
    void appear2(const int &move_y, const int &move_x){  // 플레이어 출력
        mvaddstr(move_y-this->shape_size_y+2, move_x,"|------|OO|");
        mvaddstr(move_y-this->shape_size_y+3, move_x," --@--@--- ");
    }
};

// 장애물 또는 적에 대한 structure
// 회피하는 런닝 게임이기 때문에 player와 달리 obj_RAPA에서는 life가 없다.
struct obj_RAPA{
    int x=COLS - 1, y = LINES - 1; // current location and survival life
    static const int shape_size_y = 3, shape_size_x = 10;
    void appear(const int &move_y, const int &move_x){
        mvaddstr(move_y-this->shape_size_y+1, move_x," -------- ");    // enemy python
        mvaddstr(move_y-this->shape_size_y+2, move_x,"| Python |");
        mvaddstr(move_y-this->shape_size_y+3, move_x," -------- ");
    }
};

// 캐리어 >> 다른 스트럭쳐 또는 자주 사용되는 상수 등을 한번에 옮기기 위한 스트럭쳐
// 맵을 제외한 대부분을 들고 이동한다.
struct objAll{
    Player player;
    obj_RAPA rapa[3];
    int max_y = LINES, max_x = COLS-70, timeCounter=0, ch='y';
    
};

void map_init(char **, int, int);      // init map parameter
objAll obj_init(objAll obj);    // init object parameter 
void game_start();  // main game start
void display(char **, objAll ); // display for game, ex) information, object, player etc.
objAll move(objAll obj);  // moving about player or object

