#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	ofSetWindowTitle(nazwa);
	ofDisableAlphaBlending();
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	ofSetSmoothLighting(true);
	ofEnableAntiAliasing();
	light.setPosition(0, -400, 800);

	tlo.load("xbackground.jpg");

	//--------------------------------- ustawienie blokow
	int xprzesun = -250;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			blok[i][j].loadModel("Cube44.dae"); ////blok
			blok[i][j].setScale(0.08, 0.17, 0.09);
			blok[i][j].setPosition(xprzesun, i*53, 0);
			blok[i][j].setRotation(0, 90, 0, 0, 1);
			xprzesun += 100;
		}
		xprzesun = -250;
	}
	
	

	Gracz1.setup();
	Plansza1.setup();
	Ball1.setup();
	cam.rotate(45, cam.getSideDir());
	cam.setDistance(875);

	//muzykatlo.load("vapormusic.mp3");
	//muzykatlo.play(); //muzyka
	
	//cam.rotate(10, cam.getUpDir());
	//cam.setPosition(lookatPos);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

	light.enable();
	tlo.draw(0, 0, ofGetWidth(), ofGetHeight());
	cam.begin();
		ofEnableDepthTest();

		Gracz1.draw();
		Ball1.draw(Ball1.posx);

		for (int i = 0; i <6; i++) //ryswanie blokow
		{
			for (int j = 0; j < 6; j++)
			{
				blok[i][j].drawFaces();
				if (Ball1.posx >= blok[i][j].getPosition()[0]-20 && Ball1.posx < blok[i][j].getPosition()[0] + 75 
					&& Ball1.posy >= blok[i][j].getPosition()[1]-40 && Ball1.posy <= blok[i][j].getPosition()[1] +40)
				{
					blok[i][j].setPosition(-999, -999,-600);
					Ball1.vy = -Ball1.vy;
					cout << j << endl;
				}
			}
		}

		// cout << Gracz1.x << endl;

		if (Ball1.posy == (-444.0F))
		{
			Plansza1.zyciagracza = Plansza1.zyciagracza - 1;
		}
		Plansza1.draw();

		ofSetColor(255, 255, 255);
		ofDrawBitmapString("SSSSSSSSSSSS", 900, 900);
		ofDisableDepthTest();
	cam.end();
	light.disable();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
	case 'a':
		Gracz1.move('a',Plansza1.getleftboxX());
		
		break;

	case 'd':
		Gracz1.move('d', Plansza1.getrightboxX());

		break;

	case 'p':
		
		break;
	}
}

