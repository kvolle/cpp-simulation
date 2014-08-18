#include <stdlib.h>
#include "../include/visualization.h" 
#include <cstdio>

#define KEY_ESCAPE 27

Visualization::Visualization(int argc, char **argv){
	win.width = 300;
	win.height = 900;
	win.title = "Example";
	win.field_of_view_angle = 45;
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
}

void Visualization::display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0f,0.0f,-3.0f);

	glutSwapBuffers();
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
