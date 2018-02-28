#include "camera.h"

OrtogonalCamera::OrtogonalCamera(size_t coord0,
						size_t coord1,
						const Vector &shift,
						double scale)
	: coord0(coord0),
	  coord1(coord1),
	  shift(shift),
	  scale(scale)
{}

Coords OrtogonalCamera::project(const Vector &point)
{
	auto shifted = (point + shift) * scale;
	return Coords{
		shifted.coords[coord0],
		shifted.coords[coord1],
	};
}

Line OrtogonalCamera::scanline(const Coords &coords)
{
	Line res;
	res.pos.coords[coord0] = coords.x;
	res.pos.coords[coord1] = coords.y;
	res.pos = (res.pos / scale) - shift;
	res.direction = Vector::Ident();
	res.direction.coords[coord0] = 0;
	res.direction.coords[coord1] = 0;
	return res;
}
