#include "../include/simulation.h"
#include <vector>

#define numTargets 30
#define numAgents 120

using namespace std;

Simulation::Simulation(){
    printf("Simulation Constructor Called\n");
    setUpdateCallback(new root_cb);
	srand(time(NULL));

	for (int t=0;t<numTargets;t++){
        Target * temp_target = new Target;
        targets.push_back( temp_target);
        addChild(targets[t]->target_xform);
	}
	for(int i=0;i<numAgents;i++){
        Agent temp_agent(i,targets);
        agents.push_back(temp_agent);
        addChild(agents[i].agent_xform);
	}
}
Simulation::~Simulation(){
}
void Simulation::timestep(){
    surviving_agents = 0;
	for(int j=0;j<agents.size();j++){
        //printf("Targets: %d\n",agents[j].current_target);
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

