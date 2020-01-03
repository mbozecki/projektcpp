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
	lightstart.setPosition(9999, 9999, 400); //ustawienia swiatla i tla
	tlo.load("xbackground.jpg");



	//--------------------------------- ustawienie blokow, do uporzadkowania
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
	//----------------------------------


	Menu1.setup();
	Gracz1.setup();
	Plansza1.setup();
	Ball1.setup();

	//muzykatlo.load("vapormusic.mp3");
	//muzykatlo.play(); //muzyka
	
	cam.setDistance(200);
	cam.setPosition(9999,9999, 400);
	
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){


	if (chcemenu == true) /////menu
	{
		lightstart.enable();
		cam.begin();
		ofEnableDepthTest();
		Menu1.draw();
		ofDisableDepthTest();
		cam.end();
		lightstart.disable();
	}
	else
	{
		if (rotacja == true)
		{
			cam.rotate(45, cam.getSideDir());
			rotacja = false;
		}
		
		cam.setPosition(0, 0, 0);
		cam.setDistance(875);
		light.enable();
		tlo.draw(0, 0, ofGetWidth(), ofGetHeight());
		cam.begin();
		ofEnableDepthTest();

		Gracz1.draw();
		Ball1.draw(Gracz1.x);
		
		for (int i = 0; i < 6; i++) //----------------------------------------------------------ryswanie blokow, trzeba to te¿ chyba wrzucic do klasy
		{
			for (int j = 0; j < 6; j++)
			{
				blok[i][j].drawFaces();

				if (Ball1.posx >= blok[i][j].getPosition()[0] - 20 && Ball1.posx < blok[i][j].getPosition()[0] + 75
					&& ((Ball1.posy >= blok[i][j].getPosition()[1] - 40 && Ball1.posy <= blok[i][j].getPosition()[1] -36) || (Ball1.posy >= blok[i][j].getPosition()[1] + 36 && Ball1.posy <= blok[i][j].getPosition()[1] + 40))) //zbijanie blokow ,odbicie w dol ( z do³u)
				{
					blok[i][j].setPosition(-999, -999, -600);
					sfx.load("blokwav.wav");
					sfx.play();
					Ball1.vy = -Ball1.vy;	
					//cout << j << endl;
				}

				if (((Ball1.posx >= blok[i][j].getPosition()[0] - 30 && Ball1.posx <= blok[i][j].getPosition()[0] -26) || (Ball1.posx >= blok[i][j].getPosition()[0] + 68 && Ball1.posx <= blok[i][j].getPosition()[0] + 75))
					&& Ball1.posy >= blok[i][j].getPosition()[1] - 40 && Ball1.posy <= blok[i][j].getPosition()[1] + 40) //zbijanie blokow, odbicie w bok (od lewej)
				{
					blok[i][j].setPosition(-999, -999, -600);
					sfx.load("blokwav.wav");
					sfx.play();
					Ball1.vx = -Ball1.vx;
				}

			}
		}


		if (Ball1.posy == (-444.0F)) //odejmowanie serc/¿yæ
		{
			Plansza1.zyciagracza = Plansza1.zyciagracza - 1;
			sfx2.load("sercewav.wav");
			sfx2.play();
		}

		Plansza1.draw();

		ofDisableDepthTest();
		cam.end();
		light.disable();

	}
	
	
	
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	switch (key) {
	case 'a':
		Gracz1.move('a',Plansza1.getleftboxX()); // ruch w prawo

		break;

	case 'd':
		Gracz1.move('d', Plansza1.getrightboxX());  // ruch w lewo
		
		break;

	case 'w':
		Menu1.menunawigator = 0;
		break;

	case 's':
		Menu1.menunawigator = 1;
		break;

	case OF_KEY_RETURN:   //enter

		if (Menu1.menunawigator == 1)
		{
			Menu1.menunawigator = 2;
		}
		else
		{
			chcemenu = false;
		}
		
		sfx3.load("startwav.wav");
		sfx3.play();
		sfx3.setSpeed(0.5f);
		
		break;
	}
}

