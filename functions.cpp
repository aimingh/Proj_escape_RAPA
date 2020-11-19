#include <iostream>
#include <curses.h>
#include "common.hpp"

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
