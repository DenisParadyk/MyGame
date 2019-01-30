#ifndef SECONDDISPLAY_H
#define SECONDDISPLAY_H

#include <iostream>
#include <string>
#include "logic.h"
#include "glut.h"
#include "FirstDisplay.h"
#include "varsity.h"

using namespace std;

class SecondDisplay
{
private:

	string firstPlayer;
	string secondPlayer;
	logic check;
	Varsity gameVal;
	FirstDisplay gameWindow;

public:

	void setUserDate();
	
	string getFirstUserDate();
	
	string getSecondUserDate();

	void drawGameLog(const char *text, int length, int x, int y);

	void closeGame();

	void Message();

};

#endif
