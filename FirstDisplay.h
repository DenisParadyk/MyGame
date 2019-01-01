#ifndef FIRSTDISPLAY_H
#define FIRSTDISPLAY_H

#include <glut.h>
#include <math.h>
#include <iostream>
#include "varsity.h"
#include "logic.h"

using namespace std;

class FirstDisplay
{
private:

	static logic check;

public:

	static void printConsole_map();

    static void mouse_click(int button, int state, int x, int y);

	void draw_field();

	void draw_circle(float x, float y, float r, int amountSegments);

	void draw_map();
};

#endif