#include <iostream>
#include <random>
#include <curses.h>
#include "common.hpp"
using namespace std;

// 게임 시작
void game_start(){
	initscr();		
    curs_set(0);    //invisible cursor
    timeout(30);
	keypad(stdscr, TRUE);

	objAll obj; //declare obj carrier
    obj = obj_init(obj);
	char **map = new char*[obj.max_y];  // define map
    for (int i=0; i<obj.max_y; i++){
        map[i] = new char[obj.max_x];
    }
	map_init(map, obj.max_y, obj.max_x);

    //랜덤요소
    random_device rd;
    mt19937_64 mersenne_twister_engine(rd());
    uniform_int_distribution<> dice(0,5);
    uniform_int_distribution<> dice2(0,obj.max_rapa_num-1);
    uniform_int_distribution<> dice3(0,10);
    int random_dice, target_dice, target_height;

    int sel = gameMenu();
    if(sel==12){
        while((obj.ch != 'q') && (obj.ch != 'Q')){
            display(map, obj);  //출력
            obj.ch = getch();   //키보드 입력
            obj = move(obj);    //이동
            flow_map_bg(map, obj.max_y, obj.max_x); //배경움직임
            
            // 적 생성 임시
            if(obj.timeCounter%10==0){  //판정 속도 제어
                random_dice = dice(mersenne_twister_engine);    //
                if(random_dice==0){
                    target_dice = dice2(mersenne_twister_engine);
                    target_height = dice3(mersenne_twister_engine);
                    if (obj.rapa[target_dice].exist_flag==0){
                        obj.rapa[target_dice].exist_flag=1;
                        obj.rapa[target_dice].x = obj.max_x-obj.rapa[target_dice].shape_size_x-1; 
                        obj.rapa[target_dice].y = obj.max_y - target_height - 2;
                    }

                }
            }

            obj.timeCounter++;
        }
    }else{
        display_map(map, obj.max_y, obj.max_x);
        string temp = "Game End!";
        mvprintw(obj.max_y/2, obj.max_x/2-temp.size()/2, temp.c_str());
        timeout(-1);
        getch();
    }

	endwin();
}

// 기본 맵을 초기화
void map_init(char **map, int max_y, int max_x){
    for(int i=0; i<max_y; i++){
        for (int j=0; j<max_x; j++){
            map[i][j] = ' ';
            if(i==0 || i==max_y-1 || i==2){
                if(j%3==0){map[i][j] = '*';}
                else{map[i][j] = '-';}
            }
        }
    }
}

// 스트럭쳐로 짜여진 오브젝트나 플레이어 등을 초기화
objAll obj_init(objAll obj){
    obj.max_y = MAX_Y; obj.max_x = MAX_X;
    obj.player.x = 1; obj.player.y = obj.max_y - 2; // player start location
    obj.player.jump_flag = 0;   //flag of jump
    obj.player.down_flag = 0;
    obj.rapa_num = 0;
    for(int i=0;i<obj.max_rapa_num;i++){
        obj.rapa[i].x = obj.max_x-obj.rapa[i].shape_size_x-1; 
        obj.rapa[i].y = obj.max_y - 2;    //rapa[0] start location
        obj.rapa[i].exist_flag = 0;
    }
    return obj;
}

// 화면을 출력
// 플레이어나 적, 그리고 게임 관련 정보를 출력
void display(char **map, objAll obj){
    display_map(map, obj.max_y, obj.max_x);
    for(int i=0;i<obj.max_rapa_num;i++){
        if(obj.rapa[i].exist_flag==1){
            obj.rapa[i].appear(obj.rapa[i].y, obj.rapa[i].x);
        }
    } 
    if(obj.player.down_flag==0){
        obj.player.appear1(obj.player.y,obj.player.x);
    }else{
        obj.player.appear2(obj.player.y,obj.player.x);
    }
    display_information(obj);
}

// 액션에 대한 모음
// 플레이어의 움직임이나 장애물 등의 오브젝트의 움직임 등을 통제한다.
objAll move(objAll obj){
    obj.player = move2direction(obj.ch, obj.player);
    for(int i=0;i<obj.max_rapa_num;i++){
        if(obj.rapa[i].exist_flag==1){
            obj.rapa[i] = moveObj(obj.timeCounter, obj.rapa[i]);
        }
    } 

    if(obj.player.jump_flag==1){
        obj.player = jumppingOfPlayer(obj.timeCounter, obj.player);
    }else if(obj.player.floating_flag==1){
        if(obj.timeCounter%5==5-1){
            obj.player.jump_counter--;
        }
        if(obj.player.jump_counter==0){obj.player.floating_flag=0;}
    }else{
        obj.player = gravityOfPlayer(obj.timeCounter, obj.player);
    }

    if(obj.player.down_flag==1){
        if(obj.timeCounter%5==5-1){
            obj.player.down_counter--;
        }
        if(obj.player.down_counter==0){obj.player.down_flag=0;}
    }

    return obj;
}

// 게임 시작 화면 출력 및 start game, Exit 선택
int gameMenu(){
    char **menu_map = new char*[15];
    for (int i=0; i<15; i++){
        menu_map[i] = new char[110];
    }
    // 시작 화면 구성
    menu_map[0]  = "                    ______________________________                                                             ";
    menu_map[1]  = "__________________|                  RAPA        |       ____   ____   ____   ____   ____   ____               ";
    menu_map[2]  = "XXXXXXXXXXXXXXXXXX|          |XXXXXXXXXXXXXXXXXXX|      |____  |____  |      |____| |____| |____               ";
    menu_map[3]  = "XXXXXXXXXXXXXXXXXX|          |XXXXXXXXXXXXXXXXXXX|      |____   ____| |____  |    | |      |____               ";
    menu_map[4]  = "XXXXXXXXXXXXXXXXXX|          |                   |                                                             ";
    menu_map[5]  = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX|  _________      ________         ________     ________      ";
    menu_map[6]  = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX| |   _____  \\   |  ____  \\      |   ____  \\   |  ____  \\     ";
    menu_map[7]  = "-------------------------------------------------| |  |     |  |  |  |   \\  \\     |  |____|  |  |  |   \\  \\    ";
    menu_map[8]  = "     |          |                      |         | |   -----  /   |  |____\\  \\    |  _______/   |  |____\\  \\   ";
    menu_map[9]  = "            |                      |             | |   _____  \\   |   _____   \\   |  |          |   _____   \\  ";
    menu_map[10] = "            |                      |             | |__|     \\__\\  |__|      \\__\\  |__|          |__|      \\__\\ ";
    menu_map[11] = "                                ......------|    |                                                             ";
    menu_map[12] = "              ......------``````            |    |                       Game Start                            ";
    menu_map[13] = "..------``````                              |    |                          Exit                               ";
    menu_map[14] = "                                                                                                               ";
    int ch = KEY_UP;
    int sel = 12;
    int max_y = MAX_Y;
    int max_x = MAX_X;
    while((ch != 10)){
        for(int i=0; i<15; i++){
            for (int j=0; j<110; j++){
                mvaddch(max_y/2 -7 + i,max_x/2 -55 + j,menu_map[i][j]);
            }
        }
        for(int i=0; i<max_y; i++){
            for (int j=0; j<max_x; j++){
                if (i==0||i==max_y-1){
                    mvaddch(i,j,'=');
                }
            }
        }
        mvaddstr(max_y/2-7 + sel,max_x/2 -55 + 70,">>");
        ch = getch();

        switch (ch){
            case KEY_UP:
                sel = 12; break;
            case KEY_DOWN:
                sel = 13; break;
        }
    }
    return sel;
}
