#include <random>

#include "Util.h"


/*
 *
 */
int GetRandom(void)
{
    random_device rd;
    mt19937_64 mersenne_twister_engine(rd());
    uniform_int_distribution<> dice(1, 12);

    return dice(mersenne_twister_engine);;
}