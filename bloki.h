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
	ofxAssimpModelLoader blok[6][6];
	ofSoundPlayer sfx;
};

