#include <iostream>
#include <ncursesw/curses.h>
#include <locale.h>
#include "common.hpp"
using namespace std;

//화면에서 이동 가능한 범위 판정
int is_move_ok(int y, int x){   
    int max_y = MAX_Y;
    int max_x = MAX_X;
    return !((y >max_y-3 || y<6 || x > max_x - 8 || x < 0));  // 문자 제한, 윈도우 제한
}

// 충돌에 대한 판정 (미완성)
// 적 오브젝트에 대한 충돌 판정
// 가정: a'>x'
// ((a+a'-x)>0 and (a-x)<0) or ((a+a'-(x+x'))>0 and (a-(x+x'))<0)  //x축 조건
// or
// ((b+b'-y)>0 and (b-y)<0) or ((b+b'-(y+y'))>0 and (b-(y+y'))<0)  //y축 조건
struct objAll is_collap(struct objAll obj){
    int x1 = obj.player.x, x2 = obj.player.x+obj.player.shape_size_x;
    int y1 = obj.player.y, y2;
    if(obj.player.down_flag==1){
        y2 = obj.player.y-obj.player.shape_size_y+1;
    }else{
        y2 = obj.player.y-obj.player.shape_size_y;
    }
    if(obj.player.collap_flag==0){
        for(int i=0; i<obj.max_rapa_num;i++){
            if ((x1<=obj.rapa[i].x&&obj.rapa[i].x<x2)||((x1<=obj.rapa[i].x+obj.rapa[i].shape_size_x&&obj.rapa[i].x+obj.rapa[i].shape_size_x<x2))){
                if ((y2<obj.rapa[i].y&&obj.rapa[i].y<=y1)||(y2<obj.rapa[i].y-obj.rapa[i].shape_size_y&&obj.rapa[i].y-obj.rapa[i].shape_size_y<=y1)){
                    obj.player.life--; 
                    obj.player.collap_flag=1;
                    obj.player.collap_counter=obj.player.collap_time;
                }
            }
        }
    }
    return obj;
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

//적 생성 및 초기화
struct objAll genRAPA(struct objAll obj, int target_dice, int target_height){
    if (obj.rapa[target_dice].exist_flag==0){
        obj.rapa[target_dice].exist_flag=1;
        obj.rapa[target_dice].x = obj.max_x-obj.rapa[target_dice].shape_size_x-1; 
        obj.rapa[target_dice].y = obj.max_y - target_height - 3;
    }
    return obj;
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
    string timestring = "TIME: " + to_string(obj.timeCounter);  //show time
    string lifestring = "/  LIFE: ";

    int i = 0;
    for(i =0; i<obj.player.life; i++){
    lifestring += "❤";                                        // when changing "O" to heart
    }

    mvaddstr(2, 1, timestring.c_str()); 
    mvaddstr(2, 12, lifestring.c_str());

    // 아이템　정보출력
    string Bombstring = "BOMB: Press 'b'";
    mvaddstr(2, obj.max_x-Bombstring.size()-1, Bombstring.c_str());
}

void flow_map_bg(char**map, int max_y, int max_x){
    char temp=map[0][0];
    for (int j=0; j<max_x-1; j++){
        map[0][j] = map[0][j+1];
        map[3][j] = map[3][j+1];
        map[max_y-2][j] = map[max_y-2][j+1];
        map[max_y-1][j] = map[max_y-1][j+1];
    }
    map[0][max_x-1] = temp;
    map[max_y-1][max_x-1] = temp;

    if(map[3][max_x-2]=='-' && map[3][max_x-3]=='-'){
        map[3][max_x-1] = '*';
        map[max_y-2][max_x-1] = '*';
    }else{
        map[3][max_x-1] = '-';
        map[max_y-2][max_x-1] = '-';
    }
}

struct objAll bomb(struct objAll obj){
    obj.item.exist_flag =1;
    int i = 0;
    for(i=0; i<10; i++){
        if(obj.rapa[i].exist_flag==1){
            obj.rapa[i].exist_flag=0;
        }
    }
    return obj;
}