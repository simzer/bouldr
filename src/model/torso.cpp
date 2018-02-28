#include "torso.h"

Torso::Torso(SideLimbs &left,
			 SideLimbs &right,
			 double mass,
			 Sections &sections)
	: left(left),
	  right(right),
	  _mass(mass)
{
	sections.push_back(Section(left.arm.root, left.leg.root, 0.50));
	sections.push_back(Section(right.arm.root, right.leg.root, 0.50));
	sections.push_back(Section(left.arm.root, right.arm.root, 0.40));
	sections.push_back(Section(left.leg.root, right.leg.root, 0.20));
}

Vector Torso::CoG() const
{
	return (left.arm.root.position
		  + left.leg.root.position
		  + right.arm.root.position
			+ right.leg.root.position) / 4.0;
}

void Torso::setCoG(const Vector &vector)
{
	auto shift = vector - CoG();
	left.arm.setRoot(left.arm.root.position + shift);
	right.arm.setRoot(right.arm.root.position + shift);
	left.leg.setRoot(left.leg.root.position + shift);
	right.leg.setRoot(right.leg.root.position + shift);
}

double Torso::mass() const
{
	return _mass;
}
