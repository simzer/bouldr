#ifndef SIDELIMBS_H
#define SIDELIMBS_H

#include "../static/body.h"
#include "arm.h"
#include "leg.h"

class SideLimbs : public Body
{
public:
	Arm arm;
	Leg leg;
	SideLimbs(double mass, Sections &sections);
	Vector CoG() const override;
	double mass() const override;

};

#endif // SIDELIMBS_H
