#ifndef TORSO_H
#define TORSO_H

#include "../static/body.h"
#include "joint.h"
#include "section.h"
#include "sidelimbs.h"

class Torso : public Body
{
public:
	Vector cogPos;
	Vector front;
	double angle;
	double _mass;

	SideLimbs &left;
	SideLimbs &right;

	Torso(SideLimbs &left,
		  SideLimbs &right,
		  double mass,
		  Sections &sections);

	Vector CoG() const override;
	void setCoG(const Vector &vector);
	double mass() const override;
};

#endif // TORSO_H
