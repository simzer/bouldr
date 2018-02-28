#include "line.h"

Line::Line()
{

}

Line::Line(const Vector &pos, const Vector &direction)
	: pos(pos), direction(direction.norm())
{}

Vector Line::projection(const Vector &point)
{
	return direction * (point * direction);
}

Vector Line::projectedPoint(const Vector &point)
{
	return point + distanceFrom(point);
}

Vector Line::distanceFrom(const Vector &point)
{
	return (pos - point) - projection(pos - point);
}

Vector Line::distanceTo(const Vector &point)
{
	return distanceFrom(point) * -1;
}
