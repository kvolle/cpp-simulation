#ifndef AGENT_H
#define AGENT_H

#include <iostream>
#include <cmath>
#include "target.h"
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
	target * current_target;
	bool destroyed;

	agent(int);
	~agent();
	void set_velocity();
	void update_state();	
};

#endif // AGENT_H
