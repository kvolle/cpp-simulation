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

class Agent: public osg::Referenced {
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
    Agent(int,std::vector<Target*> &);//, osg::Group* &);
    ~Agent();
	void set_velocity();
    void update_state();
};

class agent_cb: public osg::NodeCallback{//, public Agent{
public:
    int duh;
    agent_cb(){duh=0;}
    virtual void operator()(osg::Node* node, osg::NodeVisitor* nv){

        osg::ref_ptr<Agent> agentData = dynamic_cast<Agent*>(node->getUserData());
        if (agentData){
            printf("%f %f %f\n",agentData->state.position[0],agentData->state.position[1],agentData->state.position[2]);
            agentData->agent_xform->setPosition(osg::Vec3(agentData->state.position[0]-duh,agentData->state.position[1],agentData->state.position[2]));
        }
        traverse(node,nv);
        duh++;
        /*
        osg::PositionAttitudeTransform* xform = dynamic_cast<osg::PositionAttitudeTransform*>( node );
        if (xform){
            xform->setPosition(osg::Vec3(state.position[0],state.position[1],-state.position[2]));
        }*/
    }
};
#endif // AGENT_H
