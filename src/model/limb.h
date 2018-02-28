#ifndef LIMB_H
#define LIMB_H

#include "../static/body.h"
#include "joint.h"

class Limb : public Body
{
public:
	Joint &root;
	Joint &mid;
	Joint &end;
	double upperMass;
	double lowerMass;

	Limb(Joint &root,
		 Joint &mid,
		 Joint &end,
		 double upperMass,
		 double lowerMass);

	Vector CoG() const override;
	double mass() const override;
	void setRoot(const Vector &pos);
	void setEnd(const Vector &pos);
};

#endif // LIMB_H
