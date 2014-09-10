#include <stdlib.h>
#include "../include/visualization.h" 
#include <cstdio>
#include <unistd.h>
#define KEY_ESCAPE 27

Simulation  Visualization::simulation;
int Visualization::counter;
Visualization::Visualization(int argc, char **argv,Simulation sim){
	win.width = 300;
	win.height = 900;
	win.title = "Example";
	win.field_of_view_angle = 55;
	win.z_near = 1.0f;
	win.z_far = 500.0f;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(win.width,win.height);
	glutCreateWindow(win.title);
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutKeyboardFunc(keyboard);
	initialize();

    simulation =  sim;
	counter = 0;
}

void Visualization::display(){
    if ((counter<1000)&&(simulation.surviving_agents !=0)){

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        glTranslatef(-75.0f,-225.0f,-500.0f);

        simulation.timestep();
        for (int i=0;i<simulation.targets.size();i++){
            //printf("Target %d: ",i);
           // printf("%s\n", simulation.targets[i]->destroyed ? "true" : "false");
        }

        for (int j=0;j<simulation.targets.size();j++){
            if(!simulation.targets[j]->destroyed){
                glBegin(GL_QUADS);
                glColor3f(0.6,0.0,0.0);
                glVertex3f(3*simulation.targets[j]->position[0]-2,3*simulation.targets[j]->position[1]-2,0);
                glVertex3f(3*simulation.targets[j]->position[0]+2,3*simulation.targets[j]->position[1]-2,0);
                glVertex3f(3*simulation.targets[j]->position[0]+2,3*simulation.targets[j]->position[1]+2,0);
                glVertex3f(3*simulation.targets[j]->position[0]-2,3*simulation.targets[j]->position[1]+2,0);
                glEnd();
            }
            //printf("Target - %d: ",j);
            //printf("%s\n", simulation.targets[j].destroyed ? "true" : "false");
        }
        for (int i=0;i<simulation.agents.size();i++){
            if(!simulation.agents[i].destroyed){
                glBegin(GL_TRIANGLES);
                glColor3f(0.1,0.2,0.3);
                glVertex3f(3*simulation.agents[i].state.position[0]-2,3*simulation.agents[i].state.position[1],0);
                glVertex3f(3*simulation.agents[i].state.position[0]+2,3*simulation.agents[i].state.position[1],0);
                glVertex3f(3*simulation.agents[i].state.position[0],3*simulation.agents[i].state.position[1]+2,0);
                glEnd();
            }
		}
        glutSwapBuffers();

        counter++;
	} else{
        std::cout << "Exiting" << std::endl;
        std::exit(0);
	}
}

void Visualization::initialize(){
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

void Visualization::keyboard(unsigned char key, int mousePositionX,int mousePositonY){
	switch(key){
		case KEY_ESCAPE:
			exit(0);
			break;

		default:
		break;
	}
}
