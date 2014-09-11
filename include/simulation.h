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

class Simulation {
public:
    Simulation();
    ~Simulation();
    void timestep();
    std::vector<Target *> targets;
    std::vector<Agent> agents;

	int surviving_agents;
};

#endif
