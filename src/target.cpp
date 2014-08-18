#include "../include/target.h"
#include <time.h>

target::target(){
	//srand(time(NULL));

    position[0] = rand()%51;
    position[1] = rand()%51+100;
    position[2] = 0.0f;
	destroyed = false;
}
