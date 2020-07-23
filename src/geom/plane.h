#ifndef PLANE_H
#define PLANE_H

#include <optional>

#include "vector.h"
#include "line.h"

class Plane
{
public:
	Vector pos;
	Vector normal;

	Plane(const Vector &pos, const Vector &normal);

	std::optional<Vector> operator&&(const Line &line) const;

	Vector projectedPoint(const Vector &point) const;
};

#endif // PLANE_H
