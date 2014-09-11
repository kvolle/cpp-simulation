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

int main(int argc, char ** argv){
    Simulation* root = new Simulation();
    osgViewer::Viewer viewer;
    viewer.setSceneData(root);
    viewer.run();
    while(!viewer.done()){
        viewer.frame();
        //printf("Viewer loop\n");
    }
	return 0;
}
