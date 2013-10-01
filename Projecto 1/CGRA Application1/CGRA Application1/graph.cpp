#include "graph.h"

void node::setAppearence(float emissive[4], float ambient[4], float diffuse [4], float specular [4], float shininess, string texturePath){
	appearance->setAmbient(ambient);
	appearance->setDiffuse(diffuse);
	appearance->setSpecular(specular);
	appearance->setShininess(shininess);
	appearance->setTexture(texturePath);
}