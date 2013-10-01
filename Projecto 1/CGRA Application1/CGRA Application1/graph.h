#include <map>
#include <vector>
#include "transform.h"

using namespace std;

class graphElement{
	virtual void draw() const = 0;
};

class leaf:graphElement{
public:
	virtual void draw() const = 0;
};

class node:graphElement{
private:
	string id;
	vector<transform *> transforms;
	CGFappearance * appearance; //TODO EXTEND TO USE EMISSIVE

public:
	node(string id);
	void addTransform(transform * t);
	void setAppearence(float emissive[4], float ambient[4], float diffuse [4], float specular [4], float shininess, string texturePath);
	void draw(); //aplica a sua aparência e transformações, invoca draw para cada um dos descendentes
};

class graph{
private:
	map<node *, node * > nodeMap;
	vector<node *> nodes;
public:
	bool addNode(node * n);
	bool addEdge(node * parent, node * child);

};

