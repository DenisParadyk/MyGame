#ifndef VARSITY_H
#define VARSITY_H

using namespace std;

const int N = 5;
const int M = 5;

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

	int getGamerValue();
	
	void invert();

	int value = -1;
	int numb = 0;

	static int gamerValue;
	
};

#endif