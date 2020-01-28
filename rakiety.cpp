#include "rakiety.h"

rakiety::rakiety()
{

}
void rakiety::setup()
{
	for (int i = 0; i < 7; i++)
	{
		Rakieta[i].loadModel("Rocket.3ds");
		Rakieta[i].setScale(0.3, 0.1, 0.1);
		Rakieta[i].setPosition(0,-390, 10);
		Rakieta[i].setRotation(0,180, 0, 0, 1);
		Rakieta[i].setRotation(1, 180, 0, 1, 0);
		wyleciala[i] = false;
		y[i] = -390;
	}

}
void rakiety::draw(float &posx)
{
	for (int i = 0; i < 7; i++)
	{
		if (wyleciala[i])
		{
			newposx = Rakieta[i].getPosition()[0];
			y[i] = y[i] + vy;
			Rakieta[i].setPosition(newposx, y[i], 10);
		}
		else
		{
			Rakieta[i].setPosition(posx, -390, 10);
		}
		
		Rakieta[i].drawFaces();
	}

}
