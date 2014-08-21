#ifndef AGENT_H
#define AGENT_H

#include <iostream>
#include <cmath>
#include "target.h"
#include <vector>

class agent {
public:
	int agent_id;
    struct State {
        // For now assume agents are
        float position[3];
        float velocity;
		float heading;
		float descent_rate;

    } state;

    int current_target;
	bool destroyed;

    std::vector<target> all_targets;
    agent(int,std::vector<target> &);
	~agent();
	void set_velocity();
	void update_state();	
};

#endif // AGENT_H
