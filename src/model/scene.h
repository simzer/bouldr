#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "human.h"
#include "wall.h"

class Scene
{
public:
	Scene();

	const Triangle *getTriangle() const;
	Human getHuman() const;
	Wall getWall() const;
	std::vector<VectorProxy> controlPoints();
	void validate();

private:
	Human human;
	Wall wall;
};

#endif // SCENE_H
