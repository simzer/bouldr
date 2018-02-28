#include "sidelimbs.h"

SideLimbs::SideLimbs(double mass, Sections &sections)
	: arm(6/23.0 * mass, sections),
	  leg(17/23.0 * mass, sections)
{}

Vector SideLimbs::CoG() const
{
	return (arm.CoG() * arm.mass() + leg.CoG() * leg.mass()) / mass();
}

double SideLimbs::mass() const
{
	return arm.mass() + leg.mass();
}
