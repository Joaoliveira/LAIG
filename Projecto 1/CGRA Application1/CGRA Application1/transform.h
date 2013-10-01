#pragma once

#include "CGFapplication.h"

class transform
{
public:
	virtual void apply() const = 0;

};

class rotate:transform{
private:
	char * axis;
	float angle;
public:
	rotate(char * axis, float angle);
	void apply();

};

class scale:transform{
private:
	float x, y, z;
public:
	scale(float x, float y, float z);
	void apply();
};

class translate:transform{
private:
	float x, y, z;
public:
	translate(float x, float y, float z);
	void apply();
};


