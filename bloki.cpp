#include "bloki.h"
using namespace std;

bloki::bloki()
{

}

void bloki::setup()
{
	
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			blok[i][j].loadModel("Cube44.dae"); ////blok
			blok[i][j].setScale(0.08, 0.17, 0.09);
			blok[i][j].setPosition(xprzesun, i * 53, 0);
			blok[i][j].setRotation(0, 90, 0, 0, 1);
			xprzesun += 100;
		}
		xprzesun = -250;
	}
	blok[1][1].setPosition(0, 0, -600);
	blok[1][4].setPosition(0, 0, -600);
	blok[5][2].setPosition(0, 0, -600);
	blok[5][3].setPosition(0, 0, -600);
	blok[6][1].setPosition(0, 0, -600);
	blok[6][2].setPosition(0, 0, -600);
	blok[6][3].setPosition(0, 0, -600);
	blok[6][4].setPosition(0, 0, -600);
	blok[7][4].setPosition(0, 0, -600);
	blok[7][5].setPosition(0, 0, -600);
	xprzesun = -150;
	for (int i = 0; i < 4; i++)
	{
		blok[7][i].setPosition(xprzesun, -170, 0);
		xprzesun += 100;
	}
	
}

void bloki::draw(float& posx, float& posy, float& vx, float& vy)
{

	xprzesun = -150;
	for (int i = 0; i < 4; i++)
	{
		blok[7][i].setPosition(xprzesun, yprzesun, 0);
		xprzesun += 100;
		yprzesun -= vprzesun;
	}
	if (yprzesun <= -240)
	{
		vprzesun = -0.5;
	}

	if (yprzesun >= -130)
	{
		vprzesun = 0.1;
	}
	//*if (yprzesun == 150)
	//{
	//	yprzesun = +0.3;
	////}
	

	for (int i = 0; i < 8; i++) //----------------------------------------------------------odbijanie sie  blokow
	{
		for (int j = 0; j < 6; j++)
		{
			blok[i][j].drawFaces();

			if (posx >= blok[i][j].getPosition()[0] - 20 && posx < blok[i][j].getPosition()[0] + 75
				&& ((posy >= blok[i][j].getPosition()[1] - 40 && posy <= blok[i][j].getPosition()[1] - 36) || (posy >= blok[i][j].getPosition()[1] + 36 && posy <= blok[i][j].getPosition()[1] + 40))) //zbijanie blokow ,odbicie w dol ( z do)
			{
				blok[i][j].setPosition(-999, -999, -600);
				sfx.load("blokwav.wav");
				sfx.play();
				vy = -vy;
				//cout << j << endl;
			}

			if (((posx >= blok[i][j].getPosition()[0] - 30 && posx <= blok[i][j].getPosition()[0] - 26) || (posx >= blok[i][j].getPosition()[0] + 68 && posx <= blok[i][j].getPosition()[0] + 75))
				&& posy >= blok[i][j].getPosition()[1] - 40 && posy <= blok[i][j].getPosition()[1] + 40) //zbijanie blokow, odbicie w bok (od lewej)
			{
				blok[i][j].setPosition(-999, -999, -600);
				sfx.load("blokwav.wav");
				sfx.play();
				vx = -vx;
			}

		}
	}
}//w xach od lewej za malo na minusie

void bloki::update()
{

}

void bloki::kolizja(float& x, float& y)
{

}