#ifndef LINE_H
#define LINE_H

#include "vector.h"

class Line
{
public:
	Vector pos;
	Vector direction;

	Line();
	Line(const Vector &pos, const Vector &direction);

	static Line X(double y = 0, double z = 0);
	static Line Y(double x = 0, double z = 0);
	static Line Z(double x = 0, double y = 0);

	Vector pointAt(double t) const;
	Vector projection(const Vector &point) const;
	Vector projectedPoint(const Vector &point) const;
	Vector distanceFrom(const Vector &point) const;
	Vector distanceTo(const Vector &point) const;
};

#endif // LINE_H
