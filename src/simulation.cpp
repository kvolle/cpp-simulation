#include "../include/simulation.h"
#include <vector>

#define numTargets 300
#define numAgents 1000
#define KEY_ESCAPE 27

using namespace std;

Simulation::Simulation(int argc, char ** argv){
	srand(time(NULL));

	for (int t=0;t<numTargets;t++){
		target temp_target;
		targets.push_back(temp_target);
		temp_target.~target();
	}
	for(int i=0;i<numAgents;i++){
		agent temp_agent(i);
		temp_agent.current_target = &targets[(int)rand()%(numTargets+1)];
		agents.push_back(temp_agent);
		temp_agent.~agent();
	}
	/*~~~~~~~~~~ Visualization Code ~~~~~~~~~~*/
	win.width = 300;
	win.height = 900;
	win.title = "Example";
	win.field_of_view_angle = 45;
	win.z_near = 1.0f;
	win.z_far = 500.0f;

	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(win.width,win.height);
	glutCreateWindow(win.title);
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutKeyboardFunc(keyboard);
	initialize();
}
Simulation::~Simulation(){
}
void Simulation::timestep(){
	for(int j=0;j<agents.size();j++){
		agents[j].set_velocity();
		agents[j].update_state();
		if (agents[j].destroyed){
			printf("BOOM-%d\n",agents[j].agent_id);
			agents.erase(agents.begin()+j);
		}
	}
}
/*~~~~~~~~~~ Visualization Code ~~~~~~~~~~*/
void Simulation::display(){
//	if (agents.size() != 0){
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glLoadIdentity();
		glTranslatef(0.0f,0.0f,-3.0f);

		glutSwapBuffers();
//	}else{
		exit(0);
//	}
}
void Simulation::initialize(){
	glMatrixMode(GL_PROJECTION);
	glViewport(0,0,win.width,win.height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	GLfloat aspect = (GLfloat) win.width/win.height;
		gluPerspective(win.field_of_view_angle,aspect,win.z_near,win.z_far);
	glMatrixMode(GL_MODELVIEW);
	glShadeModel( GL_SMOOTH );
	glClearDepth( 1.0f );
	glEnable( GL_DEPTH_TEST );
	glDepthFunc( GL_LEQUAL );
	glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
		glClearColor(1.0, 1.0, 1.0, 1.0);
}
void Simulation::keyboard(unsigned char key, int mousePositionX,int mousePositionY){
	switch(key){
		case KEY_ESCAPE:
			exit(0);
			break;

		default:
		break;
	}
}
