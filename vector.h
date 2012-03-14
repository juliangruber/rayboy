#include <stdio.h>
#include <math.h>

#ifndef I_VECTOR_H
#define I_VECTOR_H

class Vector
{
public:
	double x, y, z;
	Vector operator-(const Vector &vector) const;
	void Normalize();
	float getLength();
};

#endif