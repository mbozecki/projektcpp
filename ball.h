#pragma once
#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "player.h"
class ball : public player
{
public:
	void setup();
	void update();
	void draw();
	void move(float &posx, float &posy);
	ball();

	ofxAssimpModelLoader pilka;
	float posx = 0;
	float posy = 0;
	float vx = 4;
	float vy = 4;
};

