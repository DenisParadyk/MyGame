#ifndef FIRSTDISPLAY_H
#define FIRSTDISPLAY_H

 
#include <math.h>
#include <csetjmp>
#include <iostream>
#include "varsity.h"
#include "logic.h"
#include <glut.h>

using namespace std;

class FirstDisplay
{
private:

	static logic check;

public:

	static int row;

	static int col;

	static void printConsole_map();

    static void mouse_click(int button, int state, int x, int y);

	void draw_field();

	void draw_circle(float x, float y, float r, int amountSegments);

	void draw_map();
};

#endif