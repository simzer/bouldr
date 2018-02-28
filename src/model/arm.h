#ifndef ARM_H
#define ARM_H

#include "joint.h"
#include "section.h"
#include "limb.h"

class Arm : public Limb
{
public:
	Joint wrist;
	Joint elbow;
	Joint shoulder;

	Arm(double mass, Sections &sections);
};

#endif // ARM_H
