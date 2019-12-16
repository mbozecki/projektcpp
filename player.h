#pragma once
#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
class player
{

public:
	void setup();
	void update();
	void draw();

	void move(char x, float Xbox);

	float getx();
	float gety(float yy);
	//--------------------------------------------------
	float x= 0;
	float y =-400;
	float z=20;
	float vx, vy;
	ofxAssimpModelLoader tekstura;
	float life = 5;
	player();
private:

};

