#ifndef SIMULATION_H
#define SIMULATION_H

#include "target.h"
#include "agent.h"
#include <vector>
#include <stdlib.h>

#include <osg/Node>
#include <osg/Group>
#include <osg/Geode>
#include <osg/Geometry>
#include <osg/Texture2D>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>
#include <osg/PositionAttitudeTransform>
#include <osgGA/TrackballManipulator>

class Simulation: public osg::Group{
public:
    Simulation();
    ~Simulation();
    void timestep();

    std::vector<Target *> targets;
    std::vector<Agent> agents;

	int surviving_agents;
    //osg::Group* root;
};

class root_cb: public osg::NodeCallback{
public:
    virtual void operator()(osg::Node* node, osg::NodeVisitor* nv){
        osg::ref_ptr<Simulation> simData = dynamic_cast<Simulation*> (node->getUserData() );
        if (simData){
            simData->timestep();
        }
        else{printf("fail\n");}
        traverse(node,nv);
    }
};
#endif
