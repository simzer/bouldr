#ifndef TENSOR_H
#define TENSOR_H

#include "vector.h"

class Tensor
{
public:
	std::array<Vector, 3> vectors;

	Tensor();
};

#endif // TENSOR_H
