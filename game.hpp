#include <curses.h>

struct Player{
    int x, y, life = 3; // current location and survival life
    static const int shape_size_y = 3, shape_size_x = 11;
    void appear(const int &move_y, const int &move_x){
        mvaddstr(move_y-this->shape_size_y+1, move_x," --------- ");    //Tayo bus
        mvaddstr(move_y-this->shape_size_y+2, move_x,"|      |OO|");
        mvaddstr(move_y-this->shape_size_y+3, move_x," --@--@--- ");
    }
};

struct obj_RAPA{
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