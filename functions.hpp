// 액션에 대한 함수
int is_move_ok(int, int);               // check obstacle to direction of moving
struct objAll is_collap(struct objAll);
struct Player move2direction(int, struct Player);                    // move to direction
struct Player gravityOfPlayer(int, struct Player);  // automatically down
struct Player jumppingOfPlayer(int, struct Player);
struct obj_RAPA moveObj(int, struct obj_RAPA);  // move to left enemy or obstacle
struct objAll genRAPA(struct objAll, int, int);
struct objAll bomb(struct objAll);
void flow_map_bg(char**, int, int);

// 출력에 대한 함수
void display_map(char **, int, int);   // display map
void display_information(objAll );  // display information on top