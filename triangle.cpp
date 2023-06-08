#include <GL/glut.h>


void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
		glColor3f(1,0,0); glVertex3f(0.25,0,0.0);
		glColor3f(0,1,0); glVertex3f(-0.25,0,0.0);
		glColor3f(0,0,1); glVertex3f(0,0.5,0.0);
	glEnd();
	glFlush();
}

int main(int argc,char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(680,420);
	glutCreateWindow("LUND");
	glutDisplayFunc(display);
	glutMainLoop();
}