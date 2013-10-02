#ifndef _SCENE_H_
#define _SCENE_H_

#include "graph.h"
#include "Element.h"


class Scene
{
public:
	Scene();
	
private:
	graph* graph;
	Element* elements;


};


#endif