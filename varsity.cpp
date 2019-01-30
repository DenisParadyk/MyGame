#include "varsity.h"

int Varsity::gamerValue = 0;
int Varsity::winer = -1;
int Varsity::numb = 0;

void Varsity::setGamerValue(bool gamerValue)
{
	this->gamerValue = gamerValue;
}

int Varsity::getGamerValue()
{
	return gamerValue;
}

void Varsity::setWiner()
{
	if(gamerValue != 0)
	{
		winer = 1;
	}
	else
	{
		winer = 0;
	}
}

int Varsity::getWiner()
{
	return winer;
}

void Varsity::invert()
{
	gamerValue = !gamerValue;
}
