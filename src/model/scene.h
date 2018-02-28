#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "human.h"
#include "vectorproxy.h"

class Scene
{
public:
	Scene();

	const Triangle *getTriangle() const;
	Human getHuman() const;
	std::vector<VectorProxy> controlPoints();

private:
	Human human;
};

#endif // SCENE_H
