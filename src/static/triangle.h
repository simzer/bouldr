#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <array>
#include "body.h"

class Triangle : public Body
{
public:
	virtual Vector point(size_t index) const = 0;

	Vector gForce() const;
	Vector tangentForceAt(size_t index) const;
	Vector normalForceAt(size_t index) const;
private:
};

#endif // TRIANGLE_H
