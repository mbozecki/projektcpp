#pragma once

#include "ofxAssimpModelLoader.h"

#include "ofMain.h"
#include "../../../../examples/templates/allAddonsExample//player.h"
#include "../../../../examples/templates/allAddonsExample/plansza.h"
#include "../../../../examples/templates/allAddonsExample/ball.h"


class ofApp : public ofBaseApp{

	public:

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		//void keyReleased(int key);
		//void mouseMoved(int x, int y );
		//void mouseDragged(int x, int y, int button);
		//void mousePressed(int x, int y, int button);
		//void mouseReleased(int x, int y, int button);
		//void mouseEntered(int x, int y);
		//void mouseExited(int x, int y);
		//void windowResized(int w, int h);
		//void dragEvent(ofDragInfo dragInfo);
		//void gotMessage(ofMessage msg);


		player Gracz1;
		plansza Plansza1;
		ball Ball1;
		ofImage tlo;
		ofEasyCam cam;
		ofVec3f lookatPos = ofVec3f(1024 / 2, 768 / 2, 900);
		ofLight	light;
		ofxAssimpModelLoader blok[6][6];
		ofSoundPlayer muzykatlo;

		std::string nazwa = "Projekt c++ Mikolaj Bozecki";
		int cornerindex = 0;
		int szerokoscokna = 1024;
		int wysokoscokna = 768;
};
