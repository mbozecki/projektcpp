#include "blokilvl2.h"
using namespace std;

blokilvl2::blokilvl2()
{

}

void blokilvl2::setup()
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

	blok[0][0].setPosition(0, 0, -600);
	blok[0][1].setPosition(0, 0, -600);
	blok[0][4].setPosition(0, 0, -600);
	blok[0][5].setPosition(0, 0, -600);
	blok[6][2].setPosition(0, 0, -600);
	blok[6][3].setPosition(0, 0, -600);
}


void blokilvl2::draw(float& posx, float& posy, float& vx, float& vy)
{

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
	} 
}

void blokilvl2::update()
{

}
