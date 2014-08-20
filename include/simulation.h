#ifndef SIMULATION_H
#define SIMULATION_H

#include "target.h"
#include "agent.h"
#include <vector>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/gl.h>

class Simulation {
public:
	std::vector<target> targets;
	std::vector<agent> agents;

	Simulation(int argc, char ** argv);
	~Simulation();
	void timestep();

	struct glutWindow{
		int width;
		int height;
		char* title;

		float field_of_view_angle;
		float z_near;
		float z_far;
	} win;

	static void display();
	void initialize();
	static void keyboard(unsigned char key, int mousePositionX,int mousePositionY);
};

#endif
