#include "graph.h"


/****************
******NODE*******
****************/
node::node(string id){
	this->id = id;
	appearance = new CGFappearance();

}
void node::setAppearence(float emissive[4], float ambient[4], float diffuse [4], float specular [4], float shininess, string texturePath){
	appearance->setAmbient(ambient);
	appearance->setDiffuse(diffuse);
	appearance->setSpecular(specular);
	appearance->setShininess(shininess);
	appearance->setTexture(texturePath);
}

string node::getID() const{
	return id;
}


void node::print() const{
	cout << id << endl;
}

bool node::operator==(node n2) const{
	return id == n2.id;
}
/****************
******GRAPH******
****************/

bool graph::addNode(node* n){
	pair<pair<string, vector<graphElement *>> , bool> p;
	p = graphMap.insert(pair<string, vector<graphElement *>>(n->getID(), vector<graphElement *>()));
	return p.second;

	/*insert() devolve um par em que o primeiro elemento é um apontador para o elemento adicionado e o segundo é um bool
	que indica o sucesso da inserção */
}

bool graph::addEdge(string parentID, graphElement* child){
	map<string, vector<graphElement *> >::iterator it;

	it = graphMap.find(parentID); //retorna map.end() se não encontrar

	if(it != graphMap.end()){
		it->second.push_back(child);
	}else return false;

}

void graph::print() const{
	vector<graphElement *>::const_iterator it;
	
}

vector<graphElement *> graph::getChildren(string id) const{
	map<string, vector<graphElement *> >::const_iterator it;

	it = graphMap.find(id); //retorna map.end() se não encontrar

	return it->second;
}