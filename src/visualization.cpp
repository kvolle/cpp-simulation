#include <stdlib.h>
#include "../include/visualization.h" 
#include <cstdio>
#include <unistd.h>
#define KEY_ESCAPE 27

Visualization::Visualization(int argc, char **argv,Simulation sim){

    simulation =  sim;
	counter = 0;
}

void Visualization::display(){
    if ((counter<1000)&&(simulation.surviving_agents !=0)){
        simulation.timestep();
        for (int i=0;i<simulation.targets.size();i++){
            //printf("Target %d: ",i);
           // printf("%s\n", simulation.targets[i]->destroyed ? "true" : "false");
        }

        for (int j=0;j<simulation.targets.size();j++){
            if(!simulation.targets[j]->destroyed){
                // TODO Plot Targets
            }
            //printf("Target - %d: ",j);
            //printf("%s\n", simulation.targets[j].destroyed ? "true" : "false");
        }
        for (int i=0;i<simulation.agents.size();i++){
            if(!simulation.agents[i].destroyed){
                // TODO Plot Agents
            }
		}

        counter++;
	} else{
        std::cout << "Exiting" << std::endl;
        std::exit(0);
	}
}
class agent_cb: public osg::NodeCallback{
public:
    virtual void operator()(osg::Node* node, osg::NodeVisitor* nv){
        osg::PositionAttitudeTransform* xform = dynamic_cast<osg::PositionAttitudeTransform*>( node );
        if (xform){
            xform->setPosition(osg::Vec3(0,0,0));
        }
    }
};
