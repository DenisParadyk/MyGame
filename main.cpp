#include "varsity.h"
#include "logic.h"
#include "FirstDisplay.h"
#include "SecondDisplay.h"

FirstDisplay  gameWindow;
SecondDisplay gameLog;
logic check;

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	gameWindow.draw_map();
	gameWindow.draw_field();

	glutSwapBuffers();

	glEnd();
}

void log()
{
	glClear(GL_COLOR_BUFFER_BIT);

	gameLog.Message();

	glutSwapBuffers();

	glEnd();
}

void timer(int)
{
	display();
	glutTimerFunc(100, timer, 0);
}

extern jmp_buf env;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, 0);

	gameLog.setUserDate();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowPosition(500, 500);
	glutInitWindowSize(w, h);
	glutCreateWindow("GameWindow");

	glClearColor(0.2, 0.2, 0.2, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, h, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glutMouseFunc(gameWindow.mouse_click);
	glutDisplayFunc(display);
	glutTimerFunc(100, timer, 0);
	
	if (!setjmp(env))
	glutMainLoop();

	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowPosition(500, 500);
	glutInitWindowSize(w, h);
	glutCreateWindow("GameLog");

	glClearColor(1.0, 1.0, 1.0, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w , h, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glutDisplayFunc(log);
	glutTimerFunc(100, timer, 0);

	glutMainLoop();

	return 0;
}