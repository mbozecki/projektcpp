#pragma once
#include "ofMain.h"
#include "ofxAssimpModelLoader.h"

class tarcza
{
public:
	tarcza();
	void setup();
	void draw(float& posy, float& vy,bool &tarczaready);
	void launch();
	void zeruj();
	ofxAssimpModelLoader neon;
};

