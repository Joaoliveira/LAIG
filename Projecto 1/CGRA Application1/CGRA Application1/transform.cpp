#include "transform.h"


rotate::rotate(char * axis, float angle){
	this->angle = angle;
	this->axis = axis;
}

void rotate::apply(){
	GLfloat axisX, axisY, axisZ;
	axisX = 0.0f;
	axisY = 0.0f;
	axisZ = 0.0f;
	if(strcmp(axis, "xx") == 0){
		axisX = 1.0f;
	}else if(strcmp(axis, "yy") == 0){
		axisY = 1.0f;
	}else if(strcmp(axis, "zz") == 0){
		axisZ = 1.0f;
	}

	glRotatef(angle, axisX, axisY, axisZ);
}

scale::scale(float x, float y, float z){
	this->x = x;
	this->y = y;
	this->z = z;
}

void scale::apply(){
	glScalef(x, y, z);
}

translate::translate(float x, float y, float z){
	this->x = x;
	this->y = y;
	this->z = z;
}

void translate::apply(){
	glTranslatef(x, y, z);
}