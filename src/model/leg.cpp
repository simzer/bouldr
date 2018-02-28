#include "leg.h"

Leg::Leg(double mass, Sections &sections)
	: Limb(hip, knee, ankle, 2/3.0 * mass, 1/3 * mass)
{
	sections.push_back(Section(hip, knee, 0.46));
	sections.push_back(Section(knee, ankle, 0.45));
}
