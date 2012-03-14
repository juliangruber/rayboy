#include "primitive.h"
#include <stdio.h>
#include <math.h>

// Dummy
Color Primitive::getColor()
{
	return color;
}

void Primitive::setColor(int r, int g, int b) {
	color.r = r; color.g = g; color.b = b;
}

void Primitive::setCenter(double x, double y, double z) {
	this->center.x = x; this->center.y = y; this->center.z = z;
}

void Primitive::setRadius(double radius) {
	this->radius = radius;
}

double Primitive::getIntersection(Ray * ray, float maxDistance)
{
	double a, b, c, d, ox, oy, oz, t;
	Vector v = ray->getDirection();
	Vector o = ray->getOrigin();
	Vector p = this->center;
	double r = this->radius;
	ox = o.x - p.x;
	oy = o.y - p.y;
	oz = o.z - p.z;
	a = 2.0*(v.x*v.x + v.y*v.y + v.z*v.z);
	b = 2.0*(v.x*ox + v.y*oy + v.z*oz);
	c = ox*ox + oy*oy + oz*oz - r*r;
	d = b*b - 2.0*a*c;
	if( d < 0.0 )
	{
		t = 0;
		return t;
	}
	a = 1.0 / a;
	d = sqrt(d);
	t = (-d - b) * a;
	if( t >= 0.0) return t;
	t = ( d - b) * a;
	if( t >= 0.0) return t;
	t = 0;
	return t;		
}