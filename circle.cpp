#include<GL/glut.h>

int xc=250 , yc=240;
void plot_point(int x, int y){
	glBegin(GL_POINTS);
		glVertex2i(xc+x,yc+y);
		glVertex2i(xc+x,yc-y);
		glVertex2i(xc-x,yc+y);
		glVertex2i(xc-x,yc-y);
		glVertex2i(xc+y,yc+x);
		glVertex2i(xc+y,yc-x);
		glVertex2i(xc-y,yc+x);
		glVertex2i(xc-y,yc-x);
	glEnd();
}

void bresenham(int r){
	int x,y;
	float pk = (5.0/4.0)-r;

	x=0;
	y=r;

	plot_point(x,y);
	while(x<y){
		x=x+1;
		if(pk<0){
			pk=pk+2*x-1;
		}
		else{
			y=y-1;
			pk=pk+2*(x-y)-1;
		}
		plot_point(x,y);
	}
	glFlush();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	int r1=100,r2=200;
	bresenham(r1);
	bresenham(r2);
}


void Init(){
	glClearColor(1.0,1.0,1.0,0);
	glColor3f(0.0,0.0,0.0);
	gluOrtho2D(0,500,0,500);
}


int main(int argc,char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(500,500);
	glutCreateWindow("CHUD");
	Init();
	glutDisplayFunc(display);
	glutMainLoop();
}
