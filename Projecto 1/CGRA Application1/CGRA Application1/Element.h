#include <string>

using namespace std;



class Element
{
public:
	Element();
	virtual void draw() const = 0;
	
private:

};

class Globals:Element{
public:
	Globals(float background[4], string drawmode,string shading, string cullFace, string cullOrder);
	void draw();
private:
	float background[4];
	string drawmode;
	string shading;
	string cullFace;
	string cullOrder;
};


