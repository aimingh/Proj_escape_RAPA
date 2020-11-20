#include <iostream>
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

    int sel = gameMenu();
    if(sel==12){
        while((obj.ch != 'q') && (obj.ch != 'Q')){
            display(map, obj);
            obj.ch = getch();
            obj = move(obj);
            flow_map_bg(map, obj.max_y, obj.max_x);
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
    obj.max_y = LINES; obj.max_x = COLS-70;
    obj.player.x = 1; obj.player.y = LINES - 2; // player start location
    obj.player.jump_flag = 0;   //flag of jump
    obj.player.down_flag = 0;
    obj.rapa[0].x = obj.max_x-obj.rapa[0].shape_size_x-1; obj.rapa[0].y = LINES - 2;    //rapa[0] start location
    return obj;
}

// 화면을 출력
// 플레이어나 적, 그리고 게임 관련 정보를 출력
void display(char **map, objAll obj){
    display_map(map, obj.max_y, obj.max_x);
    if(obj.timeCounter>10){   //test generate obj.rapa[0]
        obj.rapa[0].appear(obj.rapa[0].y, obj.rapa[0].x);
        obj.rapa[0] = moveObj(obj.timeCounter, obj.rapa[0]);
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
    if(obj.timeCounter>10){
        obj.rapa[0] = moveObj(obj.timeCounter, obj.rapa[0]);
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
    while((ch != 10)){
        for(int i=0; i<15; i++){
            for (int j=0; j<110; j++){
                mvaddch(LINES/2 -7 + i,COLS/2 -90 + j,menu_map[i][j]);
            }
        }
        for(int i=0; i<LINES; i++){
            for (int j=0; j<COLS-70; j++){
                if (i==0||i==LINES-1){
                    mvaddch(i,j,'=');
                }
            }
        }
        mvaddstr(LINES/2-7 + sel,COLS/2 -90 + 70,">>");
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
