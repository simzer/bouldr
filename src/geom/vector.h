#ifndef POINT_H
#define POINT_H

#include <array>

class Vector
{
public:
	std::array<double, 3> coords;

	Vector();
	Vector(double x, double y, double z);
	static Vector Ident();
	static Vector X(double value = 1.0);
	static Vector Y(double value = 1.0);
	static Vector Z(double value = 1.0);
	double x() const;
	double y() const;
	double z() const;
	double &x();
	double &y();
	double &z();

	Vector operator^(const Vector &vector) const;
	Vector &operator*=(double value);
	Vector operator*(double value) const;
	Vector &operator/=(double value);
	Vector operator/(double value) const;
	double operator*(const Vector &vector) const;
	Vector &operator+=(const Vector &vector);
	Vector operator+(const Vector &vector) const;
	Vector &operator-=(const Vector &vector);
	Vector operator-(const Vector &vector) const;

	Vector norm() const;
	void normalize();
	double abs() const;
	double absSqr() const;
};

#endif
