#include "line.h"

Line::Line()
{

}

Line::Line(const Vector &pos, const Vector &direction)
	: pos(pos), direction(direction.norm())
{}

Line Line::X(double y, double z)
{
	return Line(Vector(0, y, z), Vector::X());
}

Line Line::Y(double x, double z)
{
	return Line(Vector(x, 0, z), Vector::Y());
}

Line Line::Z(double x, double y)
{
	return Line(Vector(x, y, 0), Vector::Z());
}

Vector Line::pointAt(double t) const
{
	return pos + direction * t;
}

Vector Line::projection(const Vector &point) const
{
	return direction * (point * direction);
}

Vector Line::projectedPoint(const Vector &point) const
{
	return point + distanceFrom(point);
}

Vector Line::distanceFrom(const Vector &point) const
{
	return (pos - point) - projection(pos - point);
}

Vector Line::distanceTo(const Vector &point) const
{
	return distanceFrom(point) * -1;
}
