#include "XMLScene.h"

XMLScene::XMLScene(char *filename)
{

	// Read XML from file

	doc=new TiXmlDocument( filename );
	bool loadOkay = doc->LoadFile();

	if ( !loadOkay )
	{
		printf( "Could not load file '%s'. Error='%s'. Exiting.\n", filename, doc->ErrorDesc() );
		system("PAUSE");
		exit( 1 );
	}

	TiXmlElement* yafElement= doc->FirstChildElement( "yaf" );

	if (yafElement == NULL)
	{
		printf("Main yaf block element not found! Exiting!\n");
		system("PAUSE");
		exit(1);
	}

	globalElement = yafElement->FirstChildElement( "globals" );
	camerasElement = yafElement->FirstChildElement( "cameras" );
	lightingElement = yafElement->FirstChildElement( "lighting" );
	texturesElement = yafElement->FirstChildElement( "textures" );
	appearancesElement = yafElement->FirstChildElement( "appearances" );
	graphElement = yafElement->FirstChildElement( "graph" );




	// GLOBAL

	if (globalElement == NULL){
		printf("Global block not found!\n");
		system("PAUSE");
		exit(1);
	}
	else
	{
		const char* bckg;
		const char* drawmode;
		const char* shading;
		const char* cullface;
		const char* cullorder;

		float r,g,b,a;
		bckg = globalElement->Attribute("background");
		drawmode = globalElement->Attribute("drawmode");

		if ( bckg && sscanf(bckg, "%f %f %f %f", &r, &g, &b, &a) == 4)
				printf("Background values (rgba): %f %f %f %f\n", r, g, b, a);
		system("PAUSE");
	}


	if (camerasElement == NULL){
		printf("Camera block not found!\n");
		system("PAUSE");
		exit(1);
	}
	else
	{

		//Fazer leitura
	}

	if (lightingElement == NULL){
		printf("Lighting block not found!\n");
		system("PAUSE");
		exit(1);
	}
	else
	{

		//Fazer leitura
	}

	if (texturesElement == NULL){
		printf("Textures block not found!\n");
		system("PAUSE");
		exit(1);
	}

	if (graphElement == NULL){
		printf("Graph block not found!\n");
		system("PAUSE");
		exit(1);
	}
	else{

	}
	

}

XMLScene::~XMLScene()
{
	delete(doc);
}

//-------------------------------------------------------

TiXmlElement *XMLScene::findChildByAttribute(TiXmlElement *parent,const char * attr, const char *val)
	// Searches within descendants of a parent for a node that has an attribute _attr_ (e.g. an id) with the value _val_
	// A more elaborate version of this would rely on XPath expressions
{
	TiXmlElement *child=parent->FirstChildElement();
	int found=0;

	while (child && !found)
		if (child->Attribute(attr) && strcmp(child->Attribute(attr),val)==0)
			found=1;
		else
			child=child->NextSiblingElement();

	return child;
}