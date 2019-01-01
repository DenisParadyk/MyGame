#ifndef LOGIC_H
#define LOGIC_H

#include <iostream>
#include "varsity.h"

using namespace std;

class logic
{
private:

	 

public:
	Varsity c[M][N], gamerVal;

	void CheckVertical(int row, int col);

	void CheckHorizontal(int row, int col);

	void CheckFirstDiagonal();

	void CheckSecondDiagonal();

	void CheckDraw();
};

#endif