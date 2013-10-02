#include "Element.h"

Globals::Globals(float background[4], string drawmode,string shading, string cullFace, string cullOrder){
	this->background[4] = background[4];
	this->drawmode = drawmode;
	this->shading = shading;
	this->cullFace = cullFace;
	this->cullOrder = cullOrder;
}

Camera::Camera(string initial, string id, float near, float far){
	this->initial = initial;
	this->id = id;
	this->near = near;
	this->far = far;
}

PerspectiveCamera::PerspectiveCamera(string initial, string id, float near, float far,float angle, float pos[3], float target[3]):Camera(initial,id,near,far){
	this->angle = angle;
	this->pos[3] = pos[3];
	this->target[3] = target[3];

}

OrthoCamera::OrthoCamera(string initial, string id, float near, float far,float left,float right,float top,float bottom):Camera(initial,id,near,far){
	this->left = left;
	this->right = right;
	this->top = top;
	this->bottom = bottom;
}

Lighting::Lighting(bool doublesided, bool local, bool enable, float ambient[4]){
	this->doublesided = doublesided;
	this->local = local;
	this->enable = enable;
	this->ambient[4] = ambient[4];
}
Omni::Omni(bool doublesided, bool local, bool enable, float ambient[4], string id, bool enabled, float location[3], float ambientOmni[4], float diffuse[4],
		   float specular[4]):Lighting(doublesided, local, enable, ambient[4]){
			   this->id= id;
			   this->enabled = enabled;
			   this->location[3] = location[3];
			   this-> ambientOmni[4] = ambientOmni[4];
			   this->diffuse[4] = diffuse[4];
			   this->specular[4] = specular[4];

}

Spot::Spot(bool doublesided, bool local, bool enable, float ambient[4],string id, bool enabled, float location[3], float ambientSpot[4], float diffuse[4],
		   float specular[4], int angle, int expoent, float direction[3]):Lighting(doublesided, local, enable, ambient[4]){
			   this->id = id;
			   this->enabled = enabled;
			   this->location[3] = location[3];
			   this-> ambientSpot[4] = ambientSpot[4];
			   this->diffuse[4] = diffuse[4];
			   this->specular[4] = specular[4];
			   this->angle = angle;
			   this->expoent = expoent;
			   this->direction[3] = direction[3];
}

Texture::Texture(string id, string filePath){
	this->id = id;
	this->filePath = filePath;
}

Appearance::Appearance(string id, float emissive[4], float ambient[4], float diffuse [4], float specular [4], float shininess, string texturePath, float texlength_s, float texlength_t){
	this->id = id;
	this->emissive[4] = emissive[4];
	this->ambient[4] = ambient[4];
	this->diffuse[4] = diffuse[4];
	this->specular[4] = specular[4];
	this->shininess = shininess;
	this->texturePath = texturePath;
	this->texlength_s = texlength_s;
	this->texlength_t = texlength_t;
}