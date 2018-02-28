#ifndef BODY_H
#define BODY_H

#include "../geom/vector.h"

struct Body
{
	virtual Vector CoG() const = 0;
	virtual double mass() const = 0;
};

#endif // BODY_H
