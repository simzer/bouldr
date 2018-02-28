#include "arm.h"

Arm::Arm(double mass, Sections &sections)
	: Limb(shoulder, elbow, wrist, .5*mass, .5*mass)
{
	sections.push_back(Section(wrist, elbow, 0.27));
	sections.push_back(Section(elbow, shoulder, 0.30));
}
