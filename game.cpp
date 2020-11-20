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
        for (int j=0, k =0; j<max_x; j++){
            map[i][j] = ' ';
            if(i==0 || i==max_y-1 || i==3){
            //     if(j%3==0){map[i][j] = '*';}
            //     else{map[i][j] = '-';}

            k = (j+1)%176;
            // 176 - "RTC control/7.13-8.28*Big data analysis/8.31-9.4*Comprehensive flight/10.27-11.9*Custom drone production/11.10-12.3*Autonomous flight using AI/12.4-1.26*Final Project/1.11-1.27";
            switch (k) {
            case 1: map[i][j] = 'R'; break;
            case 2: map[i][j] = 'T'; break;
            case 3: map[i][j] = 'C'; break;
            case 4: map[i][j] = ' '; break;
            case 5: map[i][j] = 'c'; break;
            case 6: map[i][j] = 'o'; break;
            case 7: map[i][j] = 'n'; break;
            case 8: map[i][j] = 't'; break;
            case 9: map[i][j] = 'r'; break;
            case 10: map[i][j] = 'o'; break;
            case 11: map[i][j] = 'l'; break;
            case 12: map[i][j] = '/'; break;
            case 13: map[i][j] = '7'; break;
            case 14: map[i][j] = '.'; break;
            case 15: map[i][j] = '1'; break;
            case 16: map[i][j] = '3'; break;
            case 17: map[i][j] = '-'; break;
            case 18: map[i][j] = '8'; break;
            case 19: map[i][j] = '.'; break;
            case 20: map[i][j] = '2'; break;
            case 21: map[i][j] = '8'; break;
            case 22: map[i][j] = ' '; break;
            case 23: map[i][j] = 'B'; break;
            case 24: map[i][j] = 'i'; break;
            case 25: map[i][j] = 'g'; break;
            case 26: map[i][j] = ' '; break;
            case 27: map[i][j] = 'd'; break;
            case 28: map[i][j] = 'a'; break;
            case 29: map[i][j] = 't'; break;
            case 30: map[i][j] = 'a'; break;
            case 31: map[i][j] = ' '; break;
            case 32: map[i][j] = 'a'; break;
            case 33: map[i][j] = 'n'; break;
            case 34: map[i][j] = 'a'; break;
            case 35: map[i][j] = 'l'; break;
            case 36: map[i][j] = 'y'; break;
            case 37: map[i][j] = 's'; break;
            case 38: map[i][j] = 'i'; break;
            case 39: map[i][j] = 's'; break;
            case 40: map[i][j] = '/'; break;
            case 41: map[i][j] = '8'; break;
            case 42: map[i][j] = '.'; break;
            case 43: map[i][j] = '3'; break;
            case 44: map[i][j] = '1'; break;
            case 45: map[i][j] = '-'; break;
            case 46: map[i][j] = '9'; break;
            case 47: map[i][j] = '.'; break;
            case 48: map[i][j] = '4'; break;
            case 49: map[i][j] = ' '; break;
            case 50: map[i][j] = 'C'; break;
            case 51: map[i][j] = 'o'; break;
            case 52: map[i][j] = 'm'; break;
            case 53: map[i][j] = 'p'; break;
            case 54: map[i][j] = 'r'; break;
            case 55: map[i][j] = 'e'; break;
            case 56: map[i][j] = 'h'; break;
            case 57: map[i][j] = 'e'; break;
            case 58: map[i][j] = 'n'; break;
            case 59: map[i][j] = 's'; break;
            case 60: map[i][j] = 'i'; break;
            case 61: map[i][j] = 'v'; break;
            case 62: map[i][j] = 'e'; break;
            case 63: map[i][j] = ' '; break;
            case 64: map[i][j] = 'f'; break;
            case 65: map[i][j] = 'l'; break;
            case 66: map[i][j] = 'i'; break;
            case 67: map[i][j] = 'g'; break;
            case 68: map[i][j] = 'h'; break;
            case 69: map[i][j] = 't'; break;
            case 70: map[i][j] = '/'; break;
            case 71: map[i][j] = '1'; break;
            case 72: map[i][j] = '0'; break;
            case 73: map[i][j] = '.'; break;
            case 74: map[i][j] = '2'; break;
            case 75: map[i][j] = '7'; break;
            case 76: map[i][j] = '-'; break;
            case 77: map[i][j] = '1'; break;
            case 78: map[i][j] = '1'; break;
            case 79: map[i][j] = '.'; break;
            case 80: map[i][j] = '9'; break;
            case 81: map[i][j] = ' '; break;
            case 82: map[i][j] = 'C'; break;
            case 83: map[i][j] = 'u'; break;
            case 84: map[i][j] = 's'; break;
            case 85: map[i][j] = 't'; break;
            case 86: map[i][j] = 'o'; break;
            case 87: map[i][j] = 'm'; break;
            case 88: map[i][j] = ' '; break;
            case 89: map[i][j] = 'd'; break;
            case 90: map[i][j] = 'r'; break;
            case 91: map[i][j] = 'o'; break;
            case 92: map[i][j] = 'n'; break;
            case 93: map[i][j] = 'e'; break;
            case 94: map[i][j] = ' '; break;
            case 95: map[i][j] = 'p'; break;
            case 96: map[i][j] = 'r'; break;
            case 97: map[i][j] = 'o'; break;
            case 98: map[i][j] = 'd'; break;
            case 99: map[i][j] = 'u'; break;
            case 100: map[i][j] = 'c'; break;
            case 101: map[i][j] = 't'; break;
            case 102: map[i][j] = 'i'; break;
            case 103: map[i][j] = 'o'; break;
            case 104: map[i][j] = 'n'; break;
            case 105: map[i][j] = '/'; break;
            case 106: map[i][j] = '1'; break;
            case 107: map[i][j] = '1'; break;
            case 108: map[i][j] = '.'; break;
            case 109: map[i][j] = '1'; break;
            case 110: map[i][j] = '0'; break;
            case 111: map[i][j] = '-'; break;
            case 112: map[i][j] = '1'; break;
            case 113: map[i][j] = '2'; break;
            case 114: map[i][j] = '.'; break;
            case 115: map[i][j] = '3'; break;
            case 116: map[i][j] = ' '; break;
            case 117: map[i][j] = 'A'; break;
            case 118: map[i][j] = 'u'; break;
            case 119: map[i][j] = 't'; break;
            case 120: map[i][j] = 'o'; break;
            case 121: map[i][j] = 'n'; break;
            case 122: map[i][j] = 'o'; break;
            case 123: map[i][j] = 'm'; break;
            case 124: map[i][j] = 'o'; break;
            case 125: map[i][j] = 'u'; break;
            case 126: map[i][j] = 's'; break;
            case 127: map[i][j] = ' '; break;
            case 128: map[i][j] = 'f'; break;
            case 129: map[i][j] = 'l'; break;
            case 130: map[i][j] = 'i'; break;
            case 131: map[i][j] = 'g'; break;
            case 132: map[i][j] = 'h'; break;
            case 133: map[i][j] = 't'; break;
            case 134: map[i][j] = ' '; break;
            case 135: map[i][j] = 'u'; break;
            case 136: map[i][j] = 's'; break;
            case 137: map[i][j] = 'i'; break;
            case 138: map[i][j] = 'n'; break;
            case 139: map[i][j] = 'g'; break;
            case 140: map[i][j] = ' '; break;
            case 141: map[i][j] = 'A'; break;
            case 142: map[i][j] = 'I'; break;
            case 143: map[i][j] = '/'; break;
            case 144: map[i][j] = '1'; break;
            case 145: map[i][j] = '2'; break;
            case 146: map[i][j] = '.'; break;
            case 147: map[i][j] = '4'; break;
            case 148: map[i][j] = '-'; break;
            case 149: map[i][j] = '1'; break;
            case 150: map[i][j] = '.'; break;
            case 151: map[i][j] = '2'; break;
            case 152: map[i][j] = '6'; break;
            case 153: map[i][j] = ' '; break;
            case 154: map[i][j] = 'F'; break;
            case 155: map[i][j] = 'i'; break;
            case 156: map[i][j] = 'n'; break;
            case 157: map[i][j] = 'a'; break;
            case 158: map[i][j] = 'l'; break;
            case 159: map[i][j] = ' '; break;
            case 160: map[i][j] = 'P'; break;
            case 161: map[i][j] = 'r'; break;
            case 162: map[i][j] = 'o'; break;
            case 163: map[i][j] = 'j'; break;
            case 164: map[i][j] = 'e'; break;
            case 165: map[i][j] = 'c'; break;
            case 166: map[i][j] = 't'; break;
            case 167: map[i][j] = '/'; break;
            case 168: map[i][j] = '1'; break;
            case 169: map[i][j] = '.'; break;
            case 170: map[i][j] = '1'; break;
            case 171: map[i][j] = '1'; break;
            case 172: map[i][j] = '-'; break;
            case 173: map[i][j] = '1'; break;
            case 174: map[i][j] = '.'; break;
            case 175: map[i][j] = '2'; break;
            default: map[i][j] = '7'; break;
            }
        }
    }
}
}

// 스트럭쳐로 짜여진 오브젝트나 플레이어 등을 초기화
objAll obj_init(objAll obj){
    obj.max_y = LINES; obj.max_x = COLS-27;
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
