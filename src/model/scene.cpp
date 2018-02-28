#include "scene.h"

Scene::Scene()
	: human(70)
{
}

const Triangle *Scene::getTriangle() const
{
	return &human;
}

Human Scene::getHuman() const
{
	return human;
}

std::vector<VectorProxy> Scene::controlPoints()
{
	return human.controlPoints();
}
