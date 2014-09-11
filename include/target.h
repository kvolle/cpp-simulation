#ifndef TARGET_H
#define TARGET_H

#include <cstdlib>
#include <cstdio>
#include <osg/Node>
#include <osgDB/ReadFile>
#include <osg/PositionAttitudeTransform>

class Target{
public:
    float position[3];
	bool destroyed;
    Target();
    osg::Node* target_model;
    osg::PositionAttitudeTransform* target_xform;
};
#endif
