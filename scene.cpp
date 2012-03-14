#include "scene.h"

void Scene::addPrimitive(Primitive * primitive)
{
	primitives[primitivesCount] = *primitive;
	primitivesCount++;
}

int Scene::getPrimitivesCount()
{
	return primitivesCount;
}

Primitive * Scene::getPrimitive(int primitiveCount)
{
	return &primitives[primitiveCount];
}