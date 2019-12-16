#pragma once
#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
class plansza
{
public:
	void setup();
	void update();
	void draw();
	plansza();
	float getrightboxX();
	float getleftboxX();

	int zyciagracza = 3;
	ofBoxPrimitive box;
	ofTexture  imagetexture;
	ofPoint points[4];
	ofBoxPrimitive boxleft;
	ofBoxPrimitive boxright;
	ofMaterial material;
	ofxAssimpModelLoader serce[3];
	ofMaterial thisMaterial;
private:
	
};

