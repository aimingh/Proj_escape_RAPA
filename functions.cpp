#include <iostream>
#include <curses.h>
#include "common.hpp"
using namespace std;

// 충돌에 대한 판정 (미완성)
// 아래 충돌은 문제 없음 위 충돌 및 윈도우 밖으로 안나가도록 출동 판정 업그레이드 필요
// 볃에 대한 충돌만 인정되므로 적 오브젝트에 대한 충돌 판정 필요
int is_move_ok(int y, int x){   
    int compare_ch;
    int max_y = MAX_Y;
    int max_x = MAX_X;
    compare_ch = mvinch(y,x); // 주어진 위치 문자 return
    return !((compare_ch=='*' || y >max_y-2 || y<5 || x > max_x - 8 || x < 0));  // 문자 제한, 윈도우 제한
}

// 플레이어 움직임
// ch 키보드 입력에 따라 이동
struct Player move2direction(int ch, struct Player player){
    switch (ch)    {
        case KEY_UP:
            player.jump_flag = 1; player.jump_counter=player.jump_hight; break; //jump flag on
        case KEY_DOWN:
            player.down_flag = 1; player.down_counter=player.down_time; break;
        case KEY_LEFT:
            if (is_move_ok(player.y,player.x - 1)){player.x = player.x - 1;}; break;
        case KEY_RIGHT:
            if (is_move_ok(player.y,player.x + player.shape_size_y + 1)){player.x = player.x + 1;}; break;
    }
    return player;
}

// 중력 (자동적으로 아래로 이동)
// 지상이 아래이기 때문에 점프같은 액션으로 위로 갈 경우 아래로 자연적으로 움직임 필요
struct Player gravityOfPlayer(int counter, struct Player player){
    int maxtime = 5;
    if(counter%maxtime==maxtime-1){
        if (is_move_ok(player.y + 1,player.x)){player.y = player.y + 1;}
    }
    return player;
}

// 점프 (jump flag가 1일 때 위로 이동)
struct Player jumppingOfPlayer(int counter, struct Player player){
    int maxtime = 5;
    if(counter%maxtime==maxtime-1){
        if (is_move_ok(player.y - 1,player.x)){player.y = player.y - 1;}
        player.jump_counter--;
    }
    if(player.jump_counter<=0){
        player.jump_flag=0;
        player.floating_flag=1;
        player.jump_counter=player.jump_time;
    }
    return player;
}

// 장애물 등의 오브젝트가 자연적으로 왼쪽으로 이동
struct obj_RAPA moveObj(int counter, struct obj_RAPA rapa){
    int maxtime = 3;
    if(counter%maxtime==maxtime-1){
        rapa.x = rapa.x - 1;
    }
    if(rapa.x<0){       // 맵 끝에 가면 exsist_flag off object 소멸
        rapa.exist_flag = 0;
    }
    return rapa;
}

// 맵 출력
void display_map(char **map, int max_y, int max_x){
    for(int i=0; i<max_y; i++){
        for (int j=0; j<max_x; j++){
            mvaddch(i,j,map[i][j]);
        }
    }
}

// 게임 정보 출력
void display_information(objAll obj){
    string timestring = "time: " + to_string(obj.timeCounter);  //show time
    mvaddstr(1, 1, timestring.c_str()); 
}

void flow_map_bg(char**map, int max_y, int max_x){
    for (int j=0; j<max_x-1; j++){
        map[2][j] = map[2][j+1];
        map[max_y-1][j] = map[max_y-1][j+1];
    }
    if(map[2][max_x-2]=='-' && map[2][max_x-3]=='-'){
        map[2][max_x-1] = '*';
        map[max_y-1][max_x-1] = '*';
    }else{
        map[2][max_x-1] = '-';
        map[max_y-1][max_x-1] = '-';
    }
}