#include "functions.cpp"

void map_init(char ***, int, int);      // init map start values
void display_map(char ***, int, int);   // display map
int is_move_ok(int, int);               // check obstacle to direction of moving
void move(int, int);                    // move to direction
