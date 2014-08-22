#ifndef AGENT_H
#define AGENT_H

#include <iostream>
#include <cmath>
#include "target.h"
#include <vector>

class Agent {
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

    std::vector<Target> all_targets;
    Agent(int,std::vector<Target> &);
    ~Agent();
	void set_velocity();
	void update_state();	
};

#endif // AGENT_H
