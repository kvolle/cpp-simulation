#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include "../include/agent.h"
#include "../include/target.h"
#include "../include/simulation.h"

#include "../include/visualization.h"
#include <GL/gl.h>
#include <GL/glut.h>

using namespace std;

int main(int argc, char ** argv){
	Simulation simulation(argc,argv);
	glutMainLoop();
	return 0;
}
