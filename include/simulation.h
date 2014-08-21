#ifndef SIMULATION_H
#define SIMULATION_H

#include "target.h"
#include "agent.h"
#include <vector>
#include <stdlib.h>

class Simulation {
public:
    std::vector<target> targets;
	std::vector<agent> agents;

	int surviving_agents;
	Simulation();
	~Simulation();
	void timestep();
};

#endif
