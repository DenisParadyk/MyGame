#ifndef VARSITY_H
#define VARSITY_H

using namespace std;

const int N = 3;
const int M = 3;

const int scale = 100;

const int w = N * scale;
const int h = M * scale;


class Varsity
{
private:

	int x;
	int y;

public:

	void setGamerValue(bool gamerValue);

	void setWiner();

	int getWiner();

	int getGamerValue();
	
	void invert();

	int value = -1;

	static int numb;

	static int gamerValue;

	static int winer;
	
};

#endif