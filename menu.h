#pragma once
#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
class menu
{
public:
	void setup();
	void update();
	void draw();
	menu();
	ofPoint punkty[4];
	ofxAssimpModelLoader menus1;
	ofxAssimpModelLoader menus2;
	ofTexture  menutlo;
	ofTexture menutlodol;
	ofTexture menuopcje;
	int u = 0;
	int menunawigator = 0;
};

