#ifndef I_RAY_H
#define I_RAY_H

#include "structs.h"
#include "vector.h"

class Ray
{
private:
	Vector origin, direction;
public:
	void setOrigin(Vector origin);
	void setDirection(Vector direction);
	Vector getOrigin() {return this->origin;};
	Vector getDirection() {return this->direction;};
};

#endif