#include "../include/agent.h"
#include <time.h>
agent::agent(int id, std::vector<target> &tar): all_targets(&tar){
    agent_id = id;
    state.velocity = 0.0f;
    state.heading = 0.0f;
    state.descent_rate = 0.0f;
    destroyed = false;
    current_target = rand()%((*all_targets).size()+1);
    state.position[0]=rand()%51;
    state.position[1]=rand()%51;
    state.position[2]=30;
};
agent::~agent(){
//	printf("X: %6.3f Y: %6.3f Z: %6.3f\n",state.position[0],state.position[1],state.position[2]);
//	printf("Agent %d Destroyed\n",agent_id);
};

void
agent::set_velocity(){
    if (std::isfinite((*all_targets)[current_target].position[0])&&std::isfinite((*all_targets)[current_target].position[1])){
		// Starting with constant velocity
		// This will change for synchronization
		state.velocity = 5.0f;
        state.heading = (float)atan2(((*all_targets)[current_target].position[0]-state.position[0]),((*all_targets)[current_target].position[1]-state.position[1]));
        state.descent_rate = state.velocity*state.position[2]/sqrt(pow(((*all_targets)[current_target].position[0]-state.position[0]),2) + pow(((*all_targets)[current_target].position[1]-state.position[1]),2));
	}
	else {
		state.velocity = 5.0f;
		state.descent_rate = 0.0f;
	}
}

void
agent::update_state(){
	// Point dynamics, no rotations
	// Delta t = 0.1s (for now)
	// North-East-Down
	float world_velocity[3];
	world_velocity[0] = state.velocity*sin(state.heading);
	world_velocity[1] = state.velocity*cos(state.heading);
	world_velocity[2] = -state.descent_rate;

	// Since velocity doesn't change over the timestep, using Euler
	for(int i=0;i<3;i++){
		state.position[i] = state.position[i] + world_velocity[i]*0.1;
	}

    if (pow((*all_targets)[current_target].position[0]-state.position[0],2)+pow((*all_targets)[current_target].position[1]-state.position[1],2)+pow((*all_targets)[current_target].position[2]-state.position[2],2)<1.0f){
		destroyed = true;
		if (rand()%1000<800){
            (*all_targets)[current_target].destroyed = true;
            //current_target.position[0] = 25;
            //current_target.position[1] = 125;
		}
	}
}
