#include "plansza.h"
plansza::plansza()
{

}

void plansza::setup()
{
	box.set(650, 900, -100); ///glowna bryla planszy
	boxleft.set(25, 900, -100); 
	boxright.set(25, 900, -100); /// dwie bryly poboczne planszy

	ofLoadImage(imagetexture, "vaporka1.png"); /////////tlo planszy
	points[0].x = -325; points[0].y = -450;
	points[1].x = 325; points[1].y = -450;
	points[2].x = 325; points[2].y = 450;
	points[3].x = -325; points[3].y = 450;

	float xserca = -350;
	for (int i = 0; i < 3; i++) //rysowanie serc
	{
		xserca -= 80;
		serce[i].loadModel("Love.3ds"); ///licznik zyc 
		serce[i].setScale(0.16, 0.16, 0.16);
		serce[i].setPosition(xserca, 300, 20);
		serce[i].setRotation(0, 180, 0, 0, 1);
		serce[i].setRotation(1, 35, 1, 0, 0);
	}

	material.setDiffuseColor(ofColor::blueViolet); //nadanie materialu bry³om pobocznym
	material.setAmbientColor(ofColor::blueViolet);
	material.setSpecularColor(ofColor::white);
	//material.setShininess(128);

	//material.setEmissiveColor(ofFloatColor::green);
	material.setShininess(80);
}

void plansza::update()
{

}

void plansza::draw()
{
	if (zyciagracza==3)
	{
		serce[0].drawFaces();
		serce[1].drawFaces();
		serce[2].drawFaces();
	}
	else if (zyciagracza == 2)
	{
		serce[0].drawFaces();
		serce[1].drawFaces();
	}
	else if (zyciagracza == 1)
	{
		serce[0].drawFaces();
	}
	else
	{

	}
	
	

	box.setPosition(0, 0, -50);
	boxleft.setPosition(-330, 0, 0);
	boxright.setPosition(330, 0, 0);

	imagetexture.draw(points[0], points[1], points[2], points[3]);
	material.begin();
	boxleft.draw();
	boxright.draw();
	box.draw();
	material.end();
	
}

float plansza::getrightboxX()
{
	return boxright.getX();
}

float plansza::getleftboxX()
{
	return boxleft.getX();
}

