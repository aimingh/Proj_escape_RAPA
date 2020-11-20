#include <iostream>
#include <string>
#include <curses.h>
using namespace std;

namespace hero{
    struct tayo{ //hero character
        static const int shape_size_y = 3, shape_size_x = 3; //character size (2,2), Caution! y axis first then x axis and starts with (0,0)
        void appear(const int &move_y, const int &move_x){
            mvaddstr(move_y, move_x, "##)"); //character head, (0,2) part of in size(2,2)
            mvaddstr(move_y + 1, move_x, "##)"); //character body, (1,2) part of in size(2,2)
            mvaddstr(move_y + 2, move_x, "@ @"); //character leg, (2,2) part of in size(2,2)
            // what's difference betwween up and down setences?
            // mvaddstr(move_y + this->shape_size_y-2, move_x, "##)"); //character body, (1,2) part of in size(2,2)
            // mvaddstr(move_y + this->shape_size_y-1, move_x, "@ @"); //character leg, (2,2) part of in size(2,2)
        }
    };
}