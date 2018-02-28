#ifndef HUMAN_H
#define HUMAN_H

#include <vector>
#include "sidelimbs.h"
#include "torso.h"
#include "../static/triangle.h"
#include "vectorproxy.h"

class Human : public Triangle
{
public:
	Sections sections;
	SideLimbs left;
	SideLimbs right;
	Torso torso;

	Human(double mass);

	Vector CoG() const override;
	double mass() const override;

	Vector point(size_t index) const override;
	std::vector<VectorProxy> controlPoints();

private:
};

#endif // HUMAN_H
