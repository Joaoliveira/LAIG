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

class Camera:Element{
public:
	Camera(string initial, string id, float near, float far);
	virtual void draw() const = 0;
private:
	string initial;
	string id;
	float near;
	float far;
};

class PerspectiveCamera:Camera{
public:
	PerspectiveCamera(string initial, string id, float near, float far,float angle, float pos[3], float target[3]);
	void draw();
private:
	float angle;
	float pos[3];
	float target[3];

};

class OrthoCamera:Camera{
public:
	OrthoCamera(string initial, string id, float near, float far,float left,float right,float top,float bottom);
	void draw();
private:
	float left;
	float right;
	float top;
	float bottom;
};

class Lighting:Element{
public:
	Lighting(bool doublesided, bool local, bool enable, float ambient[4]);
	virtual void draw() const = 0;
private:
	bool doublesided;
	bool local;
	bool enable;
	float ambient[4];
};

class Omni:Lighting{
public:
	Omni(bool doublesided, bool local, bool enable, float ambient[4],string id, bool enabled, float location[3], float ambientOmni[4], float diffuse[4],
		float specular[4]);
	void draw();

private:
	string id;
	bool enabled;
	float location[3];
	float ambientOmni[4];
	float diffuse[4];
	float specular[4];
};

class Spot:Lighting{
public:
	Spot(bool doublesided, bool local, bool enable, float ambient[4],string id, bool enabled, float location[3], float ambientSpot[4], float diffuse[4],
		float specular[4], int angle, int expoent, float direction[3]);
	void draw();

private:
	string id;
	bool enabled;
	float location[3];
	float ambientSpot[4];
	float diffuse[4];
	float specular[4];
	int angle;
	int expoent;
	float direction[3];
};

class Texture{
public:
	Texture(string id, string filePath);
private:
	string id;
	string filePath;
};

class Appearance:Element{
public:
	Appearance(string id, float emissive[4], float ambient[4], float diffuse [4], float specular [4], float shininess, string texturePath, float texlength_s, float texlength_t);
	void draw();
private:
	string id;
	float emissive[4];
	float ambient[4];
	float diffuse [4];
	float specular [4];
	float shininess;
	string texturePath;
	float texlength_s;
	float texlength_t;
	Texture* texture;
};





	





