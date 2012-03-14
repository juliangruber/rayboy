#include "pixel.h"

void Pixel::setPosition(float x, float y, float z)
{
	this->position.x = x;
	this->position.y = y;
	this->position.z = z;
}

Vector Pixel::getPosition()
{
	return this->position;
}