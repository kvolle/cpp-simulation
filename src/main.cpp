#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include "../include/agent.h"
#include "../include/target.h"
#include "../include/simulation.h"
#include "../include/visualization.h"

//using namespace std;


//extern osg::Node* makeTerrain(void);

int main(int argc, char ** argv){
    Simulation* root = new Simulation();
    osg::Node* ground = osgDB::readNodeFile("../models/SnowTerrain.obj");
    //root->addChild(ground );
    osgViewer::Viewer viewer;


    osg::Camera* camera = viewer.getCamera();
    osg::Matrixd myCameraMatrix;
    osg::Matrixd cameraRotation;
    osg::Matrixd cameraTrans;
    cameraRotation.makeRotate(
                osg::DegreesToRadians(90.0),osg::Vec3(1,0,0),// roll
                osg::DegreesToRadians(0.0),osg::Vec3(0,1,0),// pitch
                osg::DegreesToRadians(90.0),osg::Vec3(0,0,1) );// yaw
    cameraTrans.makeTranslate(0,0,150);
    myCameraMatrix = cameraRotation*cameraTrans;
    osg::Matrixd i = myCameraMatrix.inverse(myCameraMatrix);
    camera->setViewMatrix(i*osg::Matrix::rotate(-(osg::PI_2),1,0,0));


    viewer.setSceneData(root);
    viewer.run();
    while(!viewer.done()){
        viewer.frame();
        //printf("Viewer loop\n");
    }
	return 0;
}
