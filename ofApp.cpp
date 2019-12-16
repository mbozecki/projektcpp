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
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			blok[i][j].loadModel("Cube44.dae"); ////blok
			blok[i][j].setScale(0.06, 0.16, 0.06);
			blok[i][j].setPosition(j*110, i*45, 0);
			blok[i][j].setRotation(0, 90, 0, 0, 1);
		}
	}
	

	Gracz1.setup();
	Plansza1.setup();
	Ball1.setup();
	cam.rotate(45, cam.getSideDir());
	cam.setDistance(875);
	
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
		Ball1.draw();

		for (int i = 0; i <6; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				blok[i][j].drawFaces();
			}
		}
		cout << Gracz1.x << endl;
		if (Ball1.posy == (-444.0F))
		{
			Plansza1.zyciagracza = Plansza1.zyciagracza - 1;
		}
		Plansza1.draw();
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

