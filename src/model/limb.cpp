#include "limb.h"

Limb::Limb(Joint &root,
		   Joint &mid,
		   Joint &end,
		   double upperMass,
		   double lowerMass)
	: root(root),
	  mid(mid),
	  end(end),
	  upperMass(upperMass),
	  lowerMass(lowerMass)
{

}

Vector Limb::CoG() const
{
	auto upperCoG = (root.position + mid.position)/2;
	auto lowerCoG = (mid.position + end.position)/2;
	return (upperCoG * upperMass + lowerCoG * lowerMass) / mass();
}

double Limb::mass() const
{
	return upperMass + lowerMass;
}

void Limb::setRoot(const Vector &pos)
{
	root.position = pos;
	mid.position = (root.position + end.position) / 2;
}

void Limb::setEnd(const Vector &pos)
{
	end.position = pos;
	mid.position = (root.position + end.position) / 2;
}
