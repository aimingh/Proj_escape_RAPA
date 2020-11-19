#include <curses.h>
#define E_TRACE ' '

struct Player
{
    int x, y, life = 3;
    static const int shape_size_y = 2, shape_size_x = 5;
    void appear(const int &move_y, const int &move_x){
        mvaddstr(move_y + this->shape_size_y-1, move_x,"*****");
        mvaddstr(move_y + this->shape_size_y, move_x,"*@*@*");
    }
};

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

void move(int x, int y){

}