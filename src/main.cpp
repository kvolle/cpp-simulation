#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include "../include/agent.h"
#include "../include/target.h"

#include "../include/visualization.h"
#include <GL/gl.h>
#include <GL/glut.h>

const int numTargets = 300;
const int numAgents = 1000;

void *plotting(){
	glutMainLoop();
};
using namespace std;
int main(int argc, char ** argv){

	srand(time(NULL));

	vector<target> targets;
	for (int i=0;i<numTargets;i++){
    	target temp_target;
		targets.push_back(temp_target);
		temp_target.~target();
	}
	vector<agent> agents;
	for(int i=0;i<numAgents;i++){
		agent temp_agent(i);
		temp_agent.current_target = &targets[(int)rand()%(numTargets+1)];
		agents.push_back(temp_agent);
		temp_agent.~agent();
	}

	int i = 0;
	while ((i<1000) && (agents.size() != 0)){
		i++;
		for(int j=0;j<agents.size();j++){
			agents[j].set_velocity();
			agents[j].update_state();
			if (agents[j].destroyed){
				printf("BOOM-%d\n",agents[j].agent_id);
				agents.erase(agents.begin()+j);
			}
		}
	}
	printf("%d\n",i);
	//printf("%f %f\n",agent_test.current_target->position[0],agent_test.current_target->position[1]);
    printf("Active agents destroyed\n");
	Visualization visualization(argc,argv);
	for (int z=0;z<1000;z++){
		glutMainLoop();
	}
	return 0;
}
