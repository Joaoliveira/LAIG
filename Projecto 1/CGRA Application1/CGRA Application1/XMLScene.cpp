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
		printf("Processing global values\n");

		float r,g,b,a;
		const char* bckg, * drawmode, * shading, * cullface, * cullorder;

		//BACKGROUND
		bckg = globalElement->Attribute("background");
		if ( bckg && sscanf(bckg, "%f %f %f %f", &r, &g, &b, &a) == 4)
			printf("Background values (rgba): %f %f %f %f\n", r, g, b, a);

		//DRAWMODE
		drawmode = globalElement->Attribute("drawmode");
		if((strcmp(drawmode, "fill") != 0) && (strcmp(drawmode, "line") != 0) && (strcmp(drawmode, "point") != 0)){
			printf("Invalid draw mode: %s\n", drawmode);
			system("PAUSE");
		}else{
			printf("Drawmode = %s\n", drawmode);
		}

		//SHADING
		shading = globalElement->Attribute("shading");

		if((strcmp(shading, "flat") != 0) && (strcmp(shading, "gouraud") != 0)){
			printf("Invalid shading: %s\n", shading);
			system("PAUSE");
		}else{
			printf("Shading = %s\n", shading);
		}

		//CULLFACE

		cullface = globalElement->Attribute("cullface");

		if((strcmp(cullface, "none") != 0) && (strcmp(cullface, "back") != 0) && (strcmp(cullface, "front") != 0) && (strcmp(cullface, "both") != 0)){
			printf("Invalid cullface: %s\n", cullface);
			system("PAUSE");
		}else{
			printf("Cullface = %s\n", cullface);
		}

		//CULL ORDER

		cullorder = globalElement->Attribute("cullorder");

		if((strcmp(cullorder, "CCW") != 0) && (strcmp(cullorder, "CW") != 0)){
			printf("Invalid cullorder: %s\n", cullorder);
			system("PAUSE");
		}else{
			printf("Cull order = %s\n", cullorder);
		}
	}

	printf("\nProcessing cameras\n");
	if (camerasElement == NULL){
		printf("Camera block not found!\n");
		system("PAUSE");
		exit(1);
	}
	else
	{
		const char *initialCamera, *cameraType, *id, *near, *far, *angle, *pos, *target, *left, *right, *top, *bottom;

		initialCamera = camerasElement->Attribute("initial");
		printf("Initial camera: %s\n", initialCamera);

		printf("Processing cameras\n");

		TiXmlElement * nextCamera = camerasElement->FirstChildElement();

		while(nextCamera){

			cameraType = nextCamera->Value();

			id = nextCamera->Attribute("id");
			near = nextCamera->Attribute("near");
			far = nextCamera->Attribute("far");
			printf("\nID: %s\nNear: %s\nFar: %s\n", id, near, far);

			if(strcmp(cameraType, "perspective") == 0){
				angle = nextCamera->Attribute("angle");
				pos = nextCamera->Attribute("pos");
				target = nextCamera->Attribute("target");
				printf("Angle: %s\nPosition: %s\nTarget: %s\n", angle, pos, target);
			}else if(strcmp(cameraType, "ortho") == 0){
				left = nextCamera->Attribute("left");
				right = nextCamera->Attribute("right");
				top = nextCamera->Attribute("top");
				bottom = nextCamera->Attribute("bottom");
				printf("Left: %s\nRight: %s\nTop: %s\nBottom: %s\n", left, right, top, bottom);
			}else printf("Invalid type of camera found: '%s'\n", cameraType);

			nextCamera = nextCamera->NextSiblingElement();
		}

	}

	if (lightingElement == NULL){
		printf("Lighting block not found!\n");
		system("PAUSE");
		exit(1);
	}
	else{
		const char *doublesided, *local, *L_enabled, *L_ambient, *id, *enabled, *location, *ambient, *diffuse, *specular, *angle, *exponent, *direction, *lightType;

		doublesided = lightingElement->Attribute("doublesided");
		local = lightingElement->Attribute("local");
		L_enabled = lightingElement->Attribute("enabled");
		L_ambient = lightingElement->Attribute("ambient");

		printf("\nProcessing lighting\n");
		printf("Doublesided: %s\nLocal: %s\nEnabled: %s\nAmbient: %s\n", doublesided, local, L_enabled, L_ambient);

		TiXmlElement * nextLight = lightingElement->FirstChildElement();

		while(nextLight){
			lightType = nextLight->Value();

			id = nextLight->Attribute("id");
			L_enabled = nextLight->Attribute("enabled");

			location = nextLight->Attribute("location");
			L_ambient = nextLight->Attribute("ambient");
			diffuse = nextLight->Attribute("diffuse");
			specular = nextLight->Attribute("specular");

			printf("\nLocation: %s\nAmbient: %s\nDiffuse: %s\nSpecular: %s\n", location, L_ambient, diffuse,specular);

			if(strcmp(lightType, "spot") == 0){
				angle = nextLight->Attribute("angle");
				exponent = nextLight->Attribute("exponent");
				direction = nextLight->Attribute("direction");
				printf("Angle: %s\nExponent: %s\nDirection: %s\n", angle, exponent,direction);
			}

			nextLight = nextLight->NextSiblingElement();
		}

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
		printf("\nProcessing scene graph\n");
		printf("Root id: %s\n", graphElement->Attribute("rootid"));
		const char * childValue;
		TiXmlElement *node=graphElement->FirstChildElement();

		while(node){
			printf("\n\nNode id '%s'\n",node->Attribute("id"));

			TiXmlElement *child=node->FirstChildElement();

			while(child){
				childValue = child->Value();

				if(strcmp(childValue, "transforms") == 0){
					TiXmlElement *transform=child->FirstChildElement();
					printf("\nTransforms:\n");

					while(transform){
						const char *transformType = transform->Value();

						if(strcmp(transformType, "translate") == 0){
							const char *tString;
							float x,y,z;

							tString = transform->Attribute("to");

							if(tString && sscanf(tString,"%f %f %f",&x, &y, &z)==3)
							{
								printf("\tTranslate with values (XYZ): %f %f %f\n", x, y, z);
							}
							else
								printf("Error parsing translate");
						}else if(strcmp(transformType, "scale") == 0){
							const char *sString;
							float x,y,z;

							sString = transform->Attribute("factor");

							if(sString && sscanf(sString,"%f %f %f",&x, &y, &z)==3)
							{
								printf("\tScale with values (XYZ): %f %f %f\n", x, y, z);
							}
							else
								printf("Error parsing scale");
						}else if(strcmp(transformType, "rotate") == 0){
							const char *angle, *axis;
							float x,y,z;

							angle = transform->Attribute("angle");
							axis = transform->Attribute("axis");

							printf("\tRotate with values(axis, angle): %s %s\n", axis, angle);
						}

						transform = transform->NextSiblingElement();
					}


				}else if(strcmp(childValue, "children") == 0){
					TiXmlElement *children =child->FirstChildElement();
					printf("\nChildren\n");
					while(children){
						const char *childrenValue = children->Value();

						if(strcmp(childrenValue, "noderef") == 0){
							printf("\tNode with id: %s\n", children->Attribute("id"));
						}else if(strcmp(childrenValue, "rectangle") == 0){

							const char *xy1, *xy2;
							float x1, y1, x2, y2;
							xy1 = children->Attribute("xy1");
							xy2 = children->Attribute("xy2");
							if((xy1 && sscanf(xy1,"%f %f",&x1, &y1)==2) && (xy2 && sscanf(xy2,"%f %f",&x2, &y2)==2))
							{
								printf("\tRectangle with coordinates(x1, y1, x2, y2): %f %f %f %f\n", x1, y1, x2, y2);
							}
							else
								printf("Error parsing a rectangle");

						}else if(strcmp(childrenValue, "triangle") == 0){
							const char *xyz1, *xyz2, *xyz3;
							float x1, y1, z1, x2, y2, z2, x3, y3, z3;
							xyz1 = children->Attribute("xyz1");
							xyz2 = children->Attribute("xyz2");
							xyz3 = children->Attribute("xyz3");
							if((xyz1 && sscanf(xyz1,"%f %f %f",&x1, &y1, &z1)==3) 
								&& (xyz2 && sscanf(xyz2,"%f %f %f",&x2, &y2, &z2)==3)
								&& (xyz3 && sscanf(xyz3,"%f %f %f",&x3, &y3, &z3)==3))
							{
								printf("\tTriangle with coordinates(XYZ): \n\t\t%f %f %f\n\t\t%f %f %f\n\t\t%f %f %f\n", x1, y1, z1, x2, y2, z2, x3, y3, z3);
							}
							else
								printf("Error parsing a triangle");
						}else if(strcmp(childrenValue, "cylinder") == 0){
							const char *baseString, *topString, *heightString, *slicesString, *stacksString;

							baseString = children->Attribute("base");
							topString = children->Attribute("top");
							heightString = children->Attribute("height");
							slicesString = children->Attribute("slices");
							stacksString = children->Attribute("stacks");
							printf("\tCylinder:\n\t\tBase: %s\n\t\tTop: %s\n\t\tHeight: %s\n\t\tSlices: %s\n\t\tStacks: %s\n\t\t",
								baseString, topString, heightString, slicesString, stacksString);

						}else if(strcmp(childrenValue, "sphere") == 0){
							const char *radiusString, *slicesString, *stacksString;

							radiusString = children->Attribute("radius");
							slicesString = children->Attribute("slices");
							stacksString = children->Attribute("stacks");

							printf("\tSphere:\n\t\tRadius: %s\n\t\tSlices: %s\n\t\tStacks: %s\n\t\t",radiusString, slicesString, stacksString);

						}else if(strcmp(childrenValue, "torus") == 0){

							const char *innerString, *outerString, *slicesString, *loopsString;

							innerString = children->Attribute("inner");
							outerString = children->Attribute("outer");
							slicesString = children->Attribute("slices");
							loopsString = children->Attribute("loops");

							printf("\tTorus:\n\t\tInner: %s\n\t\tOuter: %s\n\t\tSlices: %s\n\t\tLoops: %s\n\t\t", innerString, outerString, slicesString, loopsString);
						}

						children = children->NextSiblingElement();
					}
				}else if(strcmp(childValue, "appearanceref") == 0){
					const char* refID = child->Attribute("id");

					TiXmlElement *appearanceRef = findChildByAttribute(appearancesElement, "id", refID);
					
					const char *emissiveString, *ambientString, *diffuseString, *specularString, *shininessString, *textureRefString, *sString, *tString;

					printf("\nAppearence\n");

					emissiveString = appearanceRef->Attribute("emissive");
					ambientString = appearanceRef->Attribute("ambient");
					diffuseString = appearanceRef->Attribute("diffuse");
					specularString = appearanceRef->Attribute("specular");
					shininessString = appearanceRef->Attribute("shininess");
					textureRefString = appearanceRef->Attribute("textureref");
					sString = appearanceRef->Attribute("texlength_s");
					tString = appearanceRef->Attribute("texlength_t");

					printf("\tEmissive: %s\n\tAmbient: %s\n\tDiffuse: %s\n\tSpecular: %s\n\tShininess: %s\n\tTexture ref: %s\n\tTex length(s): %s\n\tTex length(t): %s\n\t"
						, emissiveString, ambientString, diffuseString, specularString, shininessString, textureRefString, sString,tString);
				}
				child = child->NextSiblingElement();
			}
			node = node->NextSiblingElement();
		}
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