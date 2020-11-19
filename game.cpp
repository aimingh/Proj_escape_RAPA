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

	while((obj.ch != 'q') && (obj.ch != 'Q')){
        display(map, obj);
        obj.ch = getch();
        obj = move(obj);
        obj.timeCounter++;
    }
	endwin();
}

// 기본 맵을 초기화
void map_init(char **map, int max_y, int max_x){
    for(int i=0; i<max_y; i++){
        for (int j=0; j<max_x; j++){
            map[i][j] = ' ';
            if(i==0 || i==max_y-1 || i==2){
                map[i][j] = '*';
            }
        }
    }
}

// 스트럭쳐로 짜여진 오브젝트나 플레이어 등을 초기화
objAll obj_init(objAll obj){
    obj.max_y = LINES; obj.max_x = COLS-70;
    obj.player.x = 1; obj.player.y = LINES - 2; // player start location
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
    obj.player.appear(obj.player.y,obj.player.x);
    display_information(obj);
}

// 액션에 대한 모음
// 플레이어의 움직임이나 장애물 등의 오브젝트의 움직임 등을 통제한다.
objAll move(objAll obj){
    obj.player = move2direction(obj.ch, obj.player);
    if(obj.timeCounter>10){
        obj.rapa[0] = moveObj(obj.timeCounter, obj.rapa[0]);
    }
    obj.player = gravityOfPlayer(obj.timeCounter, obj.player);
    return obj;
}