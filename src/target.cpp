#include "../include/target.h"
#include <time.h>

Target::Target(){
	//srand(time(NULL));

    position[0] = rand()%51;
    position[1] = rand()%51+100;
    position[2] = 0.0f;
	destroyed = false;

    target_xform = new osg::PositionAttitudeTransform();
    target_xform->setPosition(osg::Vec3(-position[1]*15,position[0]*15,position[2]*15) );
    double yawd = rand()%180;
    double yawr = osg::DegreesToRadians(yawd);

    target_xform->setAttitude(osg::Quat(0,0,sin(yawr),cos(yawr)));
    target_model = osgDB::readNodeFile("../models/t55/t55.obj");
    target_xform->addChild(target_model);
}
