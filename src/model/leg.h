#ifndef LEG_H
#define LEG_H

#include "joint.h"
#include "section.h"
#include "limb.h"

class Leg : public Limb
{
public:
	Joint hip;
	Joint knee;
	Joint ankle;

	Leg(double mass, Sections &sections);
};

#endif // LEG_H
