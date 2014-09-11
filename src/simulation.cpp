#include "../include/simulation.h"
#include <vector>

#define numTargets 1
#define numAgents 1

using namespace std;

Simulation::Simulation(){
    printf("Simulation Constructor Called\n");
    //osgViewer::Viewer viewer;
    root = new osg::Group();
    root->setUpdateCallback(new root_cb);
    osg::Geode* pyramidGeode = new osg::Geode();
    osg::Geometry* pyramidGeometry = new osg::Geometry();

    // Associate the pyramid geometry with the pyramid geode
    pyramidGeode->addDrawable(pyramidGeometry);
    //Add the pyramid geode to the root node of the scene graph
    root->addChild(pyramidGeode);

    osg::Vec3Array* pyramidVertices = new osg::Vec3Array;
    pyramidVertices->push_back( osg::Vec3( 0, 0, 0) );
    pyramidVertices->push_back( osg::Vec3(10, 0, 0) );
    pyramidVertices->push_back( osg::Vec3(10,10, 0) );
    pyramidVertices->push_back( osg::Vec3( 0,10, 0) );
    pyramidVertices->push_back( osg::Vec3( 5, 5,10) );

    pyramidGeometry->setVertexArray( pyramidVertices );

    osg::DrawElementsUInt* pyramidBase =
        new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
    pyramidBase->push_back(3);
    pyramidBase->push_back(2);
    pyramidBase->push_back(1);
    pyramidBase->push_back(0);
    pyramidGeometry->addPrimitiveSet(pyramidBase);

    //Repeat the same for each of the four sides. Again, vertices are
    //specified in counter-clockwise order.

    osg::DrawElementsUInt* pyramidFaceOne =
        new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0);
    pyramidFaceOne->push_back(0);
    pyramidFaceOne->push_back(1);
    pyramidFaceOne->push_back(4);
    pyramidGeometry->addPrimitiveSet(pyramidFaceOne);

    osg::DrawElementsUInt* pyramidFaceTwo =
        new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0);
    pyramidFaceTwo->push_back(1);
    pyramidFaceTwo->push_back(2);
    pyramidFaceTwo->push_back(4);
    pyramidGeometry->addPrimitiveSet(pyramidFaceTwo);

    osg::DrawElementsUInt* pyramidFaceThree =
        new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0);
    pyramidFaceThree->push_back(2);
    pyramidFaceThree->push_back(3);
    pyramidFaceThree->push_back(4);
    pyramidGeometry->addPrimitiveSet(pyramidFaceThree);

    osg::DrawElementsUInt* pyramidFaceFour =
        new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0);
    pyramidFaceFour->push_back(3);
    pyramidFaceFour->push_back(0);
    pyramidFaceFour->push_back(4);
    pyramidGeometry->addPrimitiveSet(pyramidFaceFour);

    osg::Vec4Array* colors = new osg::Vec4Array;
    colors->push_back(osg::Vec4(1.0f,0.0f,0.0f,1.0f) );
    colors->push_back(osg::Vec4(0.0f,1.0f,0.0f,1.0f) );
    colors->push_back(osg::Vec4(0.0f,0.0f,1.0f,1.0f) );
    colors->push_back(osg::Vec4(1.0f,1.0f,1.0f,1.0f) );
    colors->push_back(osg::Vec4(1.0f,0.0f,0.0f,1.0f) );

    pyramidGeometry->setColorArray(colors);
    pyramidGeometry->setColorBinding(osg::Geometry::BIND_PER_VERTEX);

	srand(time(NULL));

	for (int t=0;t<numTargets;t++){
        Target * temp_target = new Target;
        targets.push_back( temp_target);
	}
	for(int i=0;i<numAgents;i++){
        Agent temp_agent(i,targets,root);
        agents.push_back(temp_agent);
	}
}
Simulation::~Simulation(){
}
void Simulation::timestep(){
    printf("Timestep Called\n");
    surviving_agents = 0;

	for(int j=0;j<agents.size();j++){
		agents[j].set_velocity();
		agents[j].update_state();
		if (agents[j].destroyed){
            //printf("BOOM-%d\n",agents[j].agent_id);
            //agents.erase(agents.begin()+j);
		}
        else{
            surviving_agents++;
        }
	}
    /*
	for (int j=0;j<targets.size();j++){
		if (targets[j].destroyed){
            targets.erase(targets.begin()+j);
		}
    }*/
}

