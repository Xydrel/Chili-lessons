#pragma once

#include "cmath"

typedef long double LONGD64;
typedef signed short SHORT16;


class Vector2
{
public:
	// default override
	Vector2() : x(0), y(0) {}

	Vector2(LONGD64 x, LONGD64 y)
		: x(x)
		, y(y) 
	{
		magnitude = sqrt(pow(x, 2) + pow(y, 2));
	}

	Vector2(LONGD64 mag, SHORT16 theta) 
		: magnitude(mag)
		, theta(theta)
	{
		x = (magnitude*(sin(theta)));
		y = (magnitude*(cos(theta)));
	}

	~Vector2();

private:
	LONGD64 pi = (2 * acos(0.0));
	LONGD64 x, y, magnitude;
	SHORT16 theta;

};

class Vector3
{
public:
	// Default override
	Vector3() : x(0), y(0), z(0) {}

	Vector3(LONGD64 x, LONGD64 y, LONGD64 z)
		: x(x)
		, y(y)
		, z(z) 
	{
		magnitude = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	}

	Vector3(LONGD64 mag, SHORT16 theta) 
		: magnitude(mag)
		, theta(theta) 
	{
		x = (magnitude*(sin(theta)));
		y = (magnitude*(cos(theta)));
		z = (magnitude*(tan(theta)));
	}

	~Vector3();

private:
	LONGD64 pi = (2 * acos(0.0));
	LONGD64 x, y, z, magnitude;
	SHORT16 theta;

};