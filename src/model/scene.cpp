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

Wall Scene::getWall() const
{
	return wall;
}

std::vector<VectorProxy> Scene::controlPoints()
{
	return human.controlPoints();
}

void Scene::validate()
{
	for (auto &point : human.contactPoints()) {
		wall.putOnto(point);
	}
}
