#ifndef LOGIC_H
#define LOGIC_H

#include <iostream>
#include "varsity.h"

using namespace std;

class logic
{
public:

	Varsity c[M][N], gamerVal;

	bool CheckVertical(int row, int col);

	bool CheckHorizontal(int row, int col);

	bool CheckFirstDiagonal();

	bool CheckSecondDiagonal();

	bool CheckDraw();

	bool CheckAll(int row, int col);

};

#endif