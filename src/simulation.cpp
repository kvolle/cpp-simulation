#include "../include/simulation.h"
#include <vector>

#define numTargets 1
#define numAgents 9

using namespace std;

Simulation::Simulation(){
    printf("Simulation Constructor Called\n");
    osgViewer::Viewer viewer;
    osg::Group* root = new osg::Group();

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

