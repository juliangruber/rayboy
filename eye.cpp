#include "eye.h"

void Eye::setPosition(float x, float y, float z)
{
	this->position.x = x;
	this->position.y = y;
	this->position.z = z;
}

Vector Eye::getPosition()
{
	return this->position;
}