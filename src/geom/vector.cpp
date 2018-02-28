#include "vector.h"

#include <cmath>

Vector::Vector()
{
	coords[0] = 0.0;
	coords[1] = 0.0;
	coords[2] = 0.0;
}

Vector::Vector(double x, double y, double z)
{
	coords[0] = x;
	coords[1] = y;
	coords[2] = z;
}

Vector Vector::Ident()
{
	return Vector(1, 1, 1);
}

double Vector::x() const { return coords[0]; }
double Vector::y() const { return coords[1]; }
double Vector::z() const { return coords[2]; }

double &Vector::x() { return coords[0]; }
double &Vector::y() { return coords[1]; }
double &Vector::z() { return coords[2]; }

Vector Vector::operator^(const Vector &vector) const
{
	return Vector(
		coords[1] * vector.coords[2] - coords[2] * vector.coords[1],
		coords[2] * vector.coords[0] - coords[0] * vector.coords[2],
		coords[0] * vector.coords[1] - coords[1] * vector.coords[0]);
}

Vector &Vector::operator*=(double value)
{
	for(auto &c: coords) c *= value;
	return *this;
}

Vector Vector::operator*(double value) const
{
	Vector res = *this;
	res *= value;
	return res;
}

Vector &Vector::operator/=(double value)
{
	for(auto &c: coords) c /= value;
	return *this;
}

Vector Vector::operator/(double value) const
{
	Vector res = *this;
	res /= value;
	return res;
}

double Vector::operator*(const Vector &vector) const
{
	double res = 0;
	for(auto i = 0u; i < coords.size(); i++)
		res += coords[i] * vector.coords[i];
	return res;
}

Vector &Vector::operator+=(const Vector &vector)
{
	for(auto i = 0u; i < coords.size(); i++)
		coords[i] += vector.coords[i];
	return *this;
}

Vector Vector::operator+(const Vector &vector) const
{
	Vector res(*this);
	res += vector;
	return res;
}

Vector &Vector::operator-=(const Vector &vector)
{
	for(auto i = 0u; i < coords.size(); i++)
		coords[i] -= vector.coords[i];
	return *this;
}

Vector Vector::operator-(const Vector &vector) const
{
	Vector res(*this);
	res -= vector;
	return res;
}

Vector Vector::X(double value) { return Vector(value, 0, 0); }
Vector Vector::Y(double value) { return Vector(0, value, 0); }
Vector Vector::Z(double value) { return Vector(0, 0, value); }

double Vector::absSqr() const
{
	double res = 0;
	for(auto &c: coords) res += c * c;
	return res;
}

double Vector::abs() const
{
	return sqrt(absSqr());
}

void Vector::normalize()
{
	for(auto &c: coords) c /= abs();
}

Vector Vector::norm() const
{
	Vector res(*this);
	res.normalize();
	return res;
}
