#include <iostream>
#include <curses.h>
#include "common.hpp"
using namespace std;

struct obj_RAPA_FloStr1 moveObj2(int counter, struct obj_RAPA_FloStr1 rapa){
    int maxtime = 5;
    if(counter%maxtime==maxtime-1){
        rapa.x = rapa.x - 1;
    }
    return rapa;
}