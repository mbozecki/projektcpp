#include "tarcza.h"

tarcza::tarcza()
{

}
void tarcza::setup()
{
	neon.loadModel("neondae.dae");
	neon.setScale(2.25, 1.25, 1.1);
	neon.setPosition(-450, -970, -300);
	neon.setRotation(0, 90, 0, 0, 1);
	neon.setRotation(1, 180, 0, 1, 0);

}

void tarcza::draw(float& posy, float& vy, bool &tarczaready)
{
	neon.drawFaces();
	if (posy <= (-416.0F))
	{
		vy = -vy;
		neon.setPosition(-999, -999, -999);
		tarczaready = false;
	}

}