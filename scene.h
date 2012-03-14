// Die Szene verwaltet die Primitive
#include "primitive.h"
#include <stdio.h>

class Scene
{
private:
	// 1000 sollten fürs erste reichen^^
	Primitive primitives[1000];
	int primitivesCount;
public:
		Scene():primitivesCount(0) {};
	void addPrimitive(Primitive * primitive);
	int getPrimitivesCount();
	Primitive *getPrimitive(int primitiveCount);
};