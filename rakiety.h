#pragma once
#include "ofMain.h"
#include "ofxAssimpModelLoader.h"

class rakiety
{
	public:
	rakiety();
	void setup();
	void draw(float &posx);
	ofxAssimpModelLoader Rakieta[7];
	int ktora = 0;
	float y[7];
	float vy = 7.5;
	bool wyleciala[7];
	float newposx = 0;;
};

