#include "varsity.h"
#include "logic.h"
#include "FirstDisplay.h"

FirstDisplay  gameWindow;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	gameWindow.draw_field();
	gameWindow.draw_map();

	glutSwapBuffers();

	glEnd();
}

void timer(int)
{
	display();
	glutTimerFunc(100, timer, 0);
}

int main(int argc, char** argv)
{
	setlocale(0, "");

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowPosition(500, 500);
	glutInitWindowSize(w, h);
	glutCreateWindow("X_0");

	glClearColor(0.2, 0.2, 0.2, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, h, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glutDisplayFunc(display);
	glutTimerFunc(100, timer, 0);
	glutMouseFunc(gameWindow.mouse_click);

	glutMainLoop();

	return 0;
}