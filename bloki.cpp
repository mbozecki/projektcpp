#include "bloki.h"
using namespace std;

bloki::bloki()
{

}

void bloki::setup()
{
	for (int i = 0; i < 6; i++)
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
}

void bloki::draw(float &posx, float &posy,float &vx, float &vy)
{
	for (int i = 0; i < 6; i++) //----------------------------------------------------------ryswanie blokow, trzeba to te¿ chyba wrzucic do klasy
	{
		for (int j = 0; j < 6; j++)
		{
			blok[i][j].drawFaces();

			if (posx >= blok[i][j].getPosition()[0] - 20 && posx < blok[i][j].getPosition()[0] + 75
				&& ((posy >= blok[i][j].getPosition()[1] - 40 && posy <= blok[i][j].getPosition()[1] - 36) || (posy >= blok[i][j].getPosition()[1] + 36 && posy <= blok[i][j].getPosition()[1] + 40))) //zbijanie blokow ,odbicie w dol ( z do³u)
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
}

void bloki::update()
{

}

void bloki::kolizja(float& x, float& y)
{

}