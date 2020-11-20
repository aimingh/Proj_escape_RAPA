#include "common.hpp"
#include <locale.h>

int main(){
    setlocale(LC_ALL, "ko_KR.utf8");
    setlocale(LC_CTYPE, "ko_KR.utf8");
    game_start();
	return 0;
}