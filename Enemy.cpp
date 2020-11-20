#include <iostream>
#include <string>
#include <curses.h>

using namespace std;

namespace enemy{
    struct python{
        static const char shape_size_x = 6;
        void appear(const int &move_y, const int &move_x){
            mvaddstr(move_y, move_x, "PYTHON");
        }
    };

    struct css{
        static const char shape_size_x = 3;
        void appear(const int &move_y, const int &move_x){
            mvaddstr(move_y, move_x, "CSS");
        }
    };

    struct cpp{
        static const char shape_size_y = 3;
        void appear(const int &move_y, const int &move_x){
            mvaddstr(move_y-2, move_x, "C"); mvaddstr(move_y-1, move_x, "+"); mvaddstr(move_y, move_x, "+");
        }
    };

    struct html{
        static const char shape_size_y = 2, shape_size_x = 2;
        void appear(const int &move_y, const int &move_x){
            mvaddstr(move_y, move_x, "HT");
            mvaddstr(move_y+1, move_x, "ML");
        }
    };
}