#pragma once
#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
class bloki
{
public:
	
	void setup();
	void update();
	void draw(float& posx, float& posy, float& vx, float& vy);
	void kolizja(float& x, float& y);
	bloki();

	int xprzesun = -250;
	float yprzesun = -150;
	float vprzesun = 0.2;
	bool tarczaready = false;
	ofxAssimpModelLoader blok[8][6];

	ofxAssimpModelLoader specialblok[2];
	//ofxAssimpModelLoader specialblok2;
	ofSoundPlayer sfx;
	int u = 1;
};

