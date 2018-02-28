#include "triangle.h"

#include "../geom/line.h"

#include "environment.h"

Vector Triangle::gForce() const
{
	return gravity * mass();
}

Vector Triangle::tangentForceAt(size_t index) const
{
	if (index == 2) return Vector();

	auto a = point(index == 1 ? 0 : 1);
	auto b = point(index);

	auto Mcog = ((CoG() - a) ^ gForce()).abs();
	auto FB = Mcog / (b-a).abs();
	return Vector::Z(FB);
}

Vector Triangle::normalForceAt(size_t index) const
{
	auto a = point((index + 1) % 3);
	auto b = point((index + 2) % 3);
	auto c = point(index);
	auto McogAB = (Line(a, b-a).distanceTo(CoG()) ^ gForce()).abs();
	auto FcogC = McogAB / Line(a, b-a).distanceTo(c).abs();
	return ((a-c)^(b-c)).norm() * FcogC;
}
