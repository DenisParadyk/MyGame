#include "varsity.h"

int Varsity::gamerValue = 0;

void Varsity::setGamerValue(bool gamerValue)
{
	this->gamerValue = gamerValue;
}

int Varsity::getGamerValue()
{
	return gamerValue;
}

void Varsity::invert()
{
	gamerValue = !gamerValue;
}
