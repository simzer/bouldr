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

	Vector projection(const Vector &point);
	Vector projectedPoint(const Vector &point);
	Vector distanceFrom(const Vector &point);
	Vector distanceTo(const Vector &point);
};

#endif // LINE_H
