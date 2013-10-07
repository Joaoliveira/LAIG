#include <map>
#include <vector>
#include <iostream>
#include "transform.h"

using namespace std;

class graphElement{
	//virtual void draw() const = 0;
	virtual void print() const;
};

class leaf:graphElement{
public:
	virtual void draw() const = 0;
	virtual void print() const;
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
	void draw(); //TODO aplica a sua aparência e transformações, invoca draw para cada um dos descendentes
	void print() const;
	string getID() const;
	bool operator==(node n2) const;
};

class graph{
private:
	map<string, vector<graphElement *> >graphMap;
	node * rootNode;
public:
	bool addNode(node* n);
	bool addEdge(string parentID, graphElement* child);
	void print() const;
	vector<graphElement *> getChildren(string id) const;
};

