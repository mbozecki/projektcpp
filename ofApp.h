#pragma once

#include "ofxAssimpModelLoader.h"

#include "ofMain.h"
#include "../../../../examples/templates/allAddonsExample//player.h"
#include "../../../../examples/templates/allAddonsExample/plansza.h"
#include "../../../../examples/templates/allAddonsExample/ball.h"
#include "../../../../examples/templates/allAddonsExample/menu.h"


class ofApp : public ofBaseApp{

	public:

		void setup();
		void update();
		void draw();
		void keyPressed(int key);

		std::string nazwa = "Projekt C++ Mikolaj Bozecki";

		player Gracz1;
		plansza Plansza1;
		ball Ball1;
		menu Menu1;
		ofImage tlo;
		ofEasyCam cam;
		ofVec3f lookatPos = ofVec3f(1024 / 2, 768 / 2, 900);
		ofLight	light;
		ofLight lightstart;
		ofxAssimpModelLoader blok[6][6];

		ofSoundPlayer muzykatlo;
		ofSoundPlayer sfx;
		ofSoundPlayer sfx2;
		ofSoundPlayer sfx3;
		
		int cornerindex = 0;
		int szerokoscokna = 1024;
		int wysokoscokna = 768;
		bool rotacja = true;
		bool chcemenu = true;
};
