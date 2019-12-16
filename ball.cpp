#include "ball.h"

ball::ball()
{

}

void ball::setup()
{
	pilka.loadModel("toto.dae");
	//pilka.loadModel("MIKASA2.obj");
	pilka.setScale(0.06, 0.06, 0.06);
	pilka.setPosition(posx,posy, 20);
}

void ball::update()
{

}

void ball::draw()
{
	
	move(posx, posy);
	pilka.setPosition(posx, posy, 20);
	pilka.drawFaces();
}

void ball::move(float &posx,float &posy)
{

	if (posx > 300)
	{
		vx = -vx;
		posx += vx;
	}
	else if (posx < -300)
	{
		vx = -vx;
		posx += vx;
	}
	else
	{
		posx += vx;
	}
	if (posy <= -392 && posy <= -400 && posx> (x-150) && posx < (x+100)) //odbicie od gracza
	{

		vy = -vy;
		posy += vy;
	}

	if (posy > 450)
	{
		vy = -vy;
		posy += vy;
	}
	else if (posy < -440)	
	{
		vy = -vy;
		posy += vy;
	}
	else
	{
		posy += vy;
	}
}