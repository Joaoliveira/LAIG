#ifndef _XMLSCENE_H_
#define _XMLSCENE_H_

#include "tinyxml.h"

class XMLScene
{
public:
	XMLScene(char *filename);
	~XMLScene();

	static TiXmlElement *findChildByAttribute(TiXmlElement *parent,const char * attr, const char *val);
	
protected:

	TiXmlDocument* doc;

	TiXmlElement* globalElement;
	TiXmlElement* camerasElement;
	TiXmlElement* lightingElement;
    TiXmlElement* texturesElement;
	TiXmlElement* appearancesElement;
	TiXmlElement* graphElement;
};

#endif