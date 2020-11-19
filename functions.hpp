// 액션에 대한 함수
int is_move_ok(int, int);               // check obstacle to direction of moving
struct Player move2direction(int ch, struct Player player);                    // move to direction
struct Player gravityOfPlayer(int, struct Player);  // automatically down
struct obj_RAPA moveObj(int, struct obj_RAPA);  // move to left enemy or obstacle

// 출력에 대한 함수
void display_map(char **, int, int);   // display map
void display_information(objAll );  // display information on top