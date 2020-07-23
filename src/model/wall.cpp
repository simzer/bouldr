#include "wall.h"

#include <cmath>

Wall::Wall()
	: plane(Vector(), Vector(0, -cos(15 * M_PI/180), sin(15*M_PI/180)))
{

}

void Wall::putOnto(VectorProxy &point) const
{
	auto newpos = plane.projectedPoint(point.get());
	point.set(newpos);
}

Vector Wall::getPoint(const Line &scanLine) const
{
	return *(plane && scanLine);
}

std::vector<Vector> Wall::points() const
{
	std::vector<Vector> res;
	res.push_back(*(plane && Line::Y(-1.5, 0)));
	res.push_back(*(plane && Line::Y(-1.5, 3)));
	res.push_back(*(plane && Line::Y(1.5, 3)));
	res.push_back(*(plane && Line::Y(1.5, 0)));
	return res;
}
