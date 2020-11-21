#include <curses.h>

#define MAX_Y 20;
#define MAX_X 128;

// player에 대한 structure
struct Player{
    int x, y, life; // current location and survival life
    int collap_flag, collap_counter; //출돌판정 플레그
     static const int collap_time = 5;
    int jump_flag, floating_flag, jump_counter; // 점프 플래그, 체공 플레그, 점프카운터
    static const int jump_hight = 5, jump_time = 5; // 점프 높이, 점프시 최고점 체공 시간
    static const int shape_size_y = 3, shape_size_x = 11;

    void appear1(const int &move_y, const int &move_x){  // 플레이어 출력
        mvaddstr(move_y-this->shape_size_y+1, move_x," --------- ");    //Tayo bus
        mvaddstr(move_y-this->shape_size_y+2, move_x,"|     |O O|");
        mvaddstr(move_y-this->shape_size_y+3, move_x," -@--@---- ");
    }
    int down_flag, down_counter;
    static const int down_time = 3;
    void appear2(const int &move_y, const int &move_x){  // 플레이어 출력
        mvaddstr(move_y-this->shape_size_y+2, move_x,"/`````/> </");
        mvaddstr(move_y-this->shape_size_y+3, move_x,"-@--@-----");
    }
};

// 장애물 또는 적에 대한 structure
// 회피하는 런닝 게임이기 때문에 player와 달리 obj_RAPA에서는 life가 없다.
struct obj_RAPA{
    int x, y; // current location and survival life
    int exist_flag;
    static const int shape_size_y = 3, shape_size_x = 10;
    void appear(const int &move_y, const int &move_x){
        mvaddstr(move_y-this->shape_size_y+1, move_x," ------- ");    // enemy python
        mvaddstr(move_y-this->shape_size_y+2, move_x,"| Python |");
        mvaddstr(move_y-this->shape_size_y+3, move_x," -------- ");
    }
};

//　아이템　structure 
struct Item{
    int Bomb_nY ;
    int Bomb_nX ;
    int exist_flag; //사용 불가능 플래그?
    
    static const int down_time = 3;
    void appear_item(int Bomb_nY, int Bomb_nX){  // 아이템 출력
        mvaddstr(Bomb_nY, Bomb_nX, "+++++++++   B   O   M   B   ++++++++++");
    };
};

// 캐리어 >> 다른 스트럭쳐 또는 자주 사용되는 상수 등을 한번에 옮기기 위한 스트럭쳐
// 맵을 제외한 대부분을 들고 이동한다.
struct objAll{
    Player player;
    static const int max_rapa_num = 10;  // rapa 최대 출현 숫자
    int rapa_num;                       // 현재 출현중인 rapa의 숫자
    obj_RAPA rapa[max_rapa_num];
    int max_y, max_x, timeCounter=0, ch='y';
    Item item;
};

void map_init(char **, int, int);      // init map parameter
objAll obj_init(objAll obj);    // init object parameter 
void game_start();  // main game start
void display(char **, objAll ); // display for game, ex) information, object, player etc.
objAll move(objAll obj);  // moving about player or object

int gameMenu();
void gameOver();
