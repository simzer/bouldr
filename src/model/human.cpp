#include "human.h"

Human::Human(double mass)
	: left(.23 * mass, sections),
	  right(.23 * mass, sections),
	  torso(left, right, .54 * mass, sections)
{
	right.arm.setEnd(Vector(0.25,-0.5,1.5));
	left.arm.setEnd(Vector(0.25,-0.5,1.5));
	left.leg.setEnd(Vector(-0.5,0,0));
	right.leg.setEnd(Vector(0.5,0,0));
	torso.setCoG(Vector(0.2,-0.5,0.5));
}

Vector Human::CoG() const
{
	return
	(  torso.CoG() * torso.mass()
	 + left.CoG() * left.mass()
	 + right.CoG() * right.mass()
	) / mass();
}

double Human::mass() const
{
	return torso.mass() + left.mass() + right.mass();
}

Vector Human::point(size_t index) const
{
	if (index == 0) return left.leg.end.position;
	if (index == 1) return right.leg.end.position;
	else return right.arm.end.position;
}

std::vector<VectorProxy> Human::contactPoints()
{
	std::vector<VectorProxy> res;

	res.push_back(VectorProxy(
		[&](){ return left.leg.end.position; },
		[&](const Vector &v) { left.leg.end.position = v; }
	));

	res.push_back(VectorProxy(
		[&](){ return right.leg.end.position; },
		[&](const Vector &v) { right.leg.end.position = v;}
	));

	res.push_back(VectorProxy(
		[&](){ return left.arm.end.position; },
		[&](const Vector &v) { left.arm.end.position = v; }
	));

	res.push_back(VectorProxy(
		[&](){ return right.arm.end.position; },
		[&](const Vector &v) { right.arm.end.position = v; }
	));

	return res;
}

std::vector<VectorProxy> Human::controlPoints()
{
	auto res = contactPoints();

	res.push_back(VectorProxy(
		[&](){ return CoG(); },
		[&](const Vector &v) {}
	));

	return res;
}
