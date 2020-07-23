#include "plane.h"

Plane::Plane(const Vector &pos, const Vector &normal)
	: pos(pos), normal(normal.norm())
{}

std::optional<Vector> Plane::operator&&(const Line &line) const
{
	auto denom = line.direction * normal;
	if (denom == 0) return std::nullopt;
	auto t = ((pos - line.pos) * normal) / denom;
	return line.pointAt(t);
}

Vector Plane::projectedPoint(const Vector &point) const
{
	return point - (normal * ((point - pos) * normal));
}
