#pragma once

#include "graph.h"

class rectangle:leaf{
private:
	float x[2], y[2];
public:
	rectangle(float x1, float y1,float x2,float y2);
	void draw();
};


class triangle:leaf{
private:
	float x[3], y[3], z[3];
public:
	triangle(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3);
	void draw();
};

class cylinder:leaf{
private:
	float topRadius, bottomRadius, height;
	int slices, stacks;
public:
	cylinder(float topRadius, float bottomRadius, float height, int slices, int stacks);
	void draw();
};

class sphere:leaf{
private:
	float radius;
	int slices, stacks;

public:
	sphere(float radius, int slices, int stacks);
	void draw();
};

class torus{
private:
	float inner, outer;
	int slices, loops;
public:
	torus(float inner,float outer, int slices, int loops);
	void draw();
};