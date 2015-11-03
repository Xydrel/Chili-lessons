#pragma once

#include "cmath"


template <typename T>
struct Vector2
{
public:
	// default override
	Vector2() : x(0), y(0) {}

	Vector2(T x, T y)
		: x(x)
		, y(y) 
	{
		magnitude = ComputeMag();
	}

	Vector2(T mag, T theta)
		: magnitude(mag)
		, theta(theta)
	{
		x = ComputeX(magnitude, theta);
		y = ComputeY(magnitude, theta);
	}

	~Vector2();

	/* Compute self magnitude */
	T ComputeMag() { return sqrt(x*x + y*y); }

	/* Compute self x component */
	T ComputeX(T mag, T theta) { return mag*(sin(theta)); }

	/* Compute self y component */
	T ComputeY(T mag, T theta) { return mag*(cos(theta)); }

	/* Scale a vector */
	void SelfScale(T scalar) { x = scalar*x, y = scalar*y; }
	void Scale(T scalar, Vector3& vec) { vec.x = scalar*vec.x, vec.y = scalar*vec.y; }

private:
	unsigned double pi = (2 * acos(0.0));
	T x, y, magnitude;
	T theta;

};

template <typename T>
struct Vector3
{
public:
	// Default override
	Vector3() : x(0), y(0), z(0) {}

	Vector3(T x, T y, T z)
		: x(x)
		, y(y)
		, z(z) 
	{
		magnitude = ComputeMag();
	}

	Vector3(T mag, T theta)
		: magnitude(mag)
		, theta(theta) 
	{
		x = ComputeX(magnitude, theta);
		y = ComputeY(magnitude, theta);
		z = ComputeZ(magnitude, theta);
	}

	~Vector3();

	/* Compute self magnitude */
	T ComputeMag() { return sqrt(x*x + y*y + z*z); }

	/* Compute self x component */
	T ComputeX(T mag, T theta) { return mag*(sin(theta)); }

	/* Compute self y component */
	T ComputeY(T mag, T theta) { return mag*(cos(theta)); }

	/* Compute self z component */
	T ComputeZ(T mag, T theta) { return mag*(tan(theta)); }

	/* Scale a vector */
	void SelfScale(T scalar) { x = scalar*x, y = scalar*y, z = scalar*z; }
	void Scale(T scalar, Vector3& vec) { vec.x = scalar*vec.x, vec.y = scalar*vec.y, vec.z = scalar*vec.z; }

	/* Compute vector cross product */

	/* Compute vector dot product */


private:
	unsigned double pi = (2 * acos(0.0));
	T x, y, z, magnitude;
	T theta;

};