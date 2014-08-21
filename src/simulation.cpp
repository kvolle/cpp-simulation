#include "../include/simulation.h"
#include <vector>

#define numTargets 100
#define numAgents 900

using namespace std;

Simulation::Simulation(){
	srand(time(NULL));

	targets.resize(numTargets);
    printf("??????\n");
	for(int i=0;i<numAgents;i++){
        agent temp_agent(i, targets);
        agents.push_back(temp_agent);
        //temp_agent.~agent();
	}
    printf("\t");
    //surviving_agents = agents.size();

}
Simulation::~Simulation(){
}
void Simulation::timestep(){

	for(int j=0;j<agents.size();j++){
		agents[j].set_velocity();
		agents[j].update_state();
		if (agents[j].destroyed){
            printf("BOOM-%d\n",agents.size());
            agents.erase(agents.begin()+j);
		}
	}
	for (int j=0;j<targets.size();j++){
		if (targets[j].destroyed){
			targets.erase(targets.begin()+j);
		}
	}
    surviving_agents = agents.size();

}

