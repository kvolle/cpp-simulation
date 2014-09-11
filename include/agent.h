#ifndef AGENT_H
#define AGENT_H

#include <iostream>
#include <cmath>
#include "target.h"
#include <vector>
#include <osg/Group>
#include <osg/Node>
#include <osgDB/ReadFile>
#include <osg/PositionAttitudeTransform>

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

    osg::Node* agent_model;
    osg::PositionAttitudeTransform* agent_xform;

    std::vector<Target*> all_targets;
    Agent(int,std::vector<Target*> &, osg::Group* &);
    ~Agent();
	void set_velocity();
	void update_state();	
};

#endif // AGENT_H
