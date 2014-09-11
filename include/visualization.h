#include <stdlib.h>
#include "simulation.h"

#include <osg/Node>
#include <osg/Group>
#include <osg/Geode>
#include <osg/Geometry>
#include <osg/Texture2D>
#include <osgDB/ReadFile>
#include <osgViewer/Viewer>
#include <osg/PositionAttitudeTransform>
#include <osgGA/TrackballManipulator>

class Visualization{
public:
    osgViewer::Viewer viewer;
    Simulation simulation;//static Simulation simulation;
    int counter;//static int counter;
	Visualization(int, char**,Simulation);
    void display();//static void display();
};
