#include "section.h"

Section::Section(Joint &begin, Joint &end, double length)
	: joints(&begin, &end), length(length)
{
}
