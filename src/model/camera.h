#ifndef CAMERA_H
#define CAMERA_H

#include "../geom/vector.h"
#include "../geom/line.h"

struct Coords
{
	double x;
	double y;
};

struct Camera
{
	virtual Coords project(const Vector &point) = 0;
	virtual Line scanline(const Coords &coords) = 0;
};

class OrtogonalCamera : public Camera
{
public:
	OrtogonalCamera(size_t coord0, size_t coord1,
		   const Vector &shift, double scale);

	Coords project(const Vector &point) override;
	Line scanline(const Coords &coords) override;
private:
	size_t coord0;
	size_t coord1;
	Vector shift;
	double scale;
};

#endif // CAMERA_H
