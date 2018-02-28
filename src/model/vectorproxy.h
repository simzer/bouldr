#ifndef VECTORPROXY_H
#define VECTORPROXY_H

#include <functional>
#include "../geom/vector.h"

class VectorProxy
{
public:
	typedef std::function<void(const Vector&)> Setter;
	typedef std::function<Vector()> Getter;
	VectorProxy() : bound(false) {}
	VectorProxy(const Getter &getter, const Setter &setter) :
		getter(getter), setter(setter), bound(true)
	{}
	const Vector &get() const { return getter ? getter() : Vector(); }
	void set(const Vector &v) const { if (setter) setter(v); }
	bool valid() const { return bound; }
private:
	bool bound;
	Getter getter;
	Setter setter;
};

#endif // VECTORPROXY_H
