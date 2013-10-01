#include "primitives.h"

rectangle::rectangle(float x1, float y1, float x2, float y2){
	x[0] = x1;
	y[0] = y1;
	x[1] = x2;
	y[1] = y2;
}

triangle::triangle(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3){
	x[0] = x1;
	y[0] = y1;
	z[0] = z1;

	x[1] = x2;
	y[1] = y2;
	z[1] = z2;

	x[2] = x3;
	y[2] = y3;
	z[2] = z3;
}

cylinder::cylinder(float topRadius, float bottomRadius, float height, int slices, int stacks){
	this->topRadius = topRadius;
	this->bottomRadius = bottomRadius;
	this->height = height;
	this->slices = slices;
	this->stacks = stacks;
}

sphere::sphere(float radius, int slices, int stacks){
	this->radius = radius;
	this->slices = slices;
	this->stacks = stacks;
}

torus::torus(float inner,float outer, int slices, int loops){
	this->inner = inner;
	this->outer = outer;
	this->slices = slices;
	this->loops = loops;
}