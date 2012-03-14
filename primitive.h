#ifndef I_PRIMITIVE_H
#define I_PRIMITIVE_H

#include "structs.h"
#include "vector.h"
#include "ray.h"
#include "math.h"

// Dummy: Es gibt zuerst nur Kugeln als Primitive

class Primitive
{
private:
	Color color;
	Vector center;
	double radius;
public:
	Color getColor();
	void setColor(int r, int g, int b);
	void setCenter(double x, double y, double z);
	void setRadius(double radius);
	double getIntersection(Ray * ray, float maxDistance);
	Vector getCenter() {return this->center;};
};

#endif