#include "bloki.h"
using namespace std;

bloki::bloki()
{

}

void bloki::setup()
{
	sfx.load("blokwav.wav"); // dzwiek uderzenia bloku
	
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			blok[i][j].loadModel("Cube44.dae"); ////bloki zwykle
			blok[i][j].setScale(0.08, 0.17, 0.09);
			blok[i][j].setPosition(xprzesun, (i * 53), 0);
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

	for (int i = 0; i < 1; i++)
	{
		specialblok[i].loadModel("3d-model.dae");
		specialblok[i].setScale(0.11, 0.1, 0.08);
		specialblok[i].setRotation(0, 75, 1, 0, 0);
		specialblok[i].setRotation(1, 40, 0, 0, 1);
	}	
	specialblok[0].setPosition(-150, 50, 13);	
	specialblok[1].setPosition(+140, 50, 13);

}

void bloki::draw(float& posx, float& posy, float& vx, float& vy)
{

	xprzesun = -135;
	for (int i = 0; i < 4; i++)
	{
		blok[7][i].setPosition(xprzesun, yprzesun, 0);
		xprzesun += 90;
		yprzesun -= vprzesun;
		blok[7][i].drawFaces();

		if (posx >= blok[7][0].getPosition()[0] - 40 && posx < blok[7][0].getPosition()[0] + 328
			&& ((posy >= blok[7][0].getPosition()[1] - 41 && posy <= blok[7][0].getPosition()[1] - 35) || (posy >= blok[7][0].getPosition()[1] + 34 && posy <= blok[7][0].getPosition()[1] + 42))) //zbijanie blokow ,odbicie w dol ( z do)
		{
			blok[7][0].setPosition(-999, -999, -600);

			sfx.play();
			vy = -vy;
		}

		if (((posx >= blok[7][0].getPosition()[0] - 42 && posx <= blok[7][0].getPosition()[0] - 26) || (posx >= blok[7][0].getPosition()[0] + 316 && posx <= blok[7][0].getPosition()[0] + 327))
			&& posy >= blok[7][0].getPosition()[1] - 41 && posy <= blok[7][0].getPosition()[1] + 41) //zbijanie blokow, odbicie w bok (od lewej)
		{
			blok[7][0].setPosition(-999, -999, -600);
			sfx.play();
			vx = -vx;
		}
	}
	if (yprzesun <= -230)
	{
		vprzesun = -0.25;
	}

	if (yprzesun >= -80)
	{
		vprzesun = 0.08;
	}

	for (int i = 0; i < 7; i++) //----------------------------------------------------------odbijanie sie  blokow
	{
		for (int j = 0; j < 6; j++)
		{
			blok[i][j].drawFaces();

			if (posx >= blok[i][j].getPosition()[0] - 40 && posx < blok[i][j].getPosition()[0] + 74
				&& ((posy >= blok[i][j].getPosition()[1] - 41 && posy <= blok[i][j].getPosition()[1] - 35) || (posy >= blok[i][j].getPosition()[1] + 34 && posy <= blok[i][j].getPosition()[1] + 42))) //zbijanie blokow ,odbicie w dol ( z do)
			{
				blok[i][j].setPosition(-999, -999, -600);
				
				sfx.play();
				sfx.setSpeed(1.0f);
				vy = -vy;
			}

			if (((posx >= blok[i][j].getPosition()[0] - 42 && posx <= blok[i][j].getPosition()[0] - 26) || (posx >= blok[i][j].getPosition()[0] + 68 && posx <= blok[i][j].getPosition()[0] + 73))
				&& posy >= blok[i][j].getPosition()[1] - 41 && posy <= blok[i][j].getPosition()[1] + 41) //zbijanie blokow, odbicie w bok (od lewej)
			{
				blok[i][j].setPosition(-999, -999, -600);
				sfx.play();
				sfx.setSpeed(1.0f);
				vx = -vx;
			}

		}
	} // dla zwyklych blokow

	for (int i = 0; i < 1; i++)
	{
		if (posx >= specialblok[i].getPosition()[0] - 20 && posx < specialblok[i].getPosition()[0] + 34
			&& ((posy >= specialblok[i].getPosition()[1] - 22 && posy <= specialblok[i].getPosition()[1] - 16) || (posy >= specialblok[i].getPosition()[1] + 15 && posy <= specialblok[i].getPosition()[1] + 22))) //zbijanie blokow ,odbicie w dol ( z do)
		{
			specialblok[i].setPosition(-999, -999, -600);
			tarczaready = true;
			sfx.play();
			sfx.setSpeed(0.7f);
			vy = -vy;
		}

		if (((posx >= specialblok[i].getPosition()[0] - 19 && posx <= specialblok[i].getPosition()[0] - 13) || (posx >= specialblok[i].getPosition()[0] + 34 && posx <= specialblok[i].getPosition()[0] + 36))
			&& posy >= specialblok[i].getPosition()[1] - 20 && posy <= specialblok[i].getPosition()[1] + 20) //zbijanie blokow, odbicie w bok (od lewej)
		{
			specialblok[i].setPosition(-999, -999, -600);
			sfx.play();
			sfx.setSpeed(0.7f);
			tarczaready = true;
			vx = -vx;
		}
		specialblok[i].drawFaces();
	} // dla specialbloku


}

void bloki::update()
{


	if (u < 360) // rotacja figurek
	{
		specialblok[0].setRotation(1, u, 0, 1, 0);
		specialblok[1].setRotation(1, -u, 0, 1, 0);
		u = u + 1.3;
	}
	else
	{
		u = 0;
	}


}
