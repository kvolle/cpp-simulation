#ifndef TARGET_H
#define TARGET_H

#include <cstdlib>
#include <cstdio>

class Target{
public:
    float position[3];
	bool destroyed;
    Target();
};
#endif
