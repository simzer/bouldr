#ifndef WALL_H
#define WALL_H

#include <vector>

#include "../geom/plane.h"
#include "vectorproxy.h"

class Wall
{
public:
	Wall();
	void putOnto(VectorProxy &point) const;
	Vector getPoint(const Line &scanLine) const;
	std::vector<Vector> points() const;
private:
	Plane plane;
};

#endif // WALL_H
