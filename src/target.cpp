#include "../include/target.h"
#include <time.h>

Target::Target(){
	//srand(time(NULL));
    printf("Target constructor called\n");
    position[0] = rand()%51;
    position[1] = rand()%51+100;
    position[2] = 0.0f;
	destroyed = false;
}
