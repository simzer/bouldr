#ifndef SECTION_H
#define SECTION_H

#include <vector>

#include "joint.h"

class Section
{
public:
	double length;
	std::pair<Joint*, Joint*> joints;

	Section(Joint &begin, Joint &end, double length);
};

typedef std::vector<Section> Sections;

#endif // SECTION_H
