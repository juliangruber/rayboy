#include "vector.h"

Vector Vector::operator-(const Vector &vector) const {
	Vector t_vector = *this;
	t_vector.x = x - vector.x;
	t_vector.y = y - vector.y;
	t_vector.z = z - vector.z;
	return t_vector;
};

void Vector::Normalize()
{
	float l = 1.0f / getLength(); x *= l; y *= l; z *= l;
}

float Vector::getLength()
{
	return (float)sqrt( x * x + y * y + z * z );
}