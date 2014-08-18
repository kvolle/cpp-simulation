#include <stdlib.h>
#include <GL/glut.h>
#include <GL/gl.h>

class Visualization{
public:
typedef struct{
	int width;
	int height;
	char* title;

	float field_of_view_angle;
	float z_near;
	float z_far;
} glutWindow;

glutWindow win;
Visualization(int, char**);
static void display();
void initialize();
static void keyboard(unsigned char key, int mousePositionX,int mousePositonY);
};
