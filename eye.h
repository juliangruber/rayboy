#include "structs.h"
#include "vector.h"

class Eye
{
private:
	Vector position;
public:
	void setPosition(float x, float y, float z);
	Vector getPosition();
};