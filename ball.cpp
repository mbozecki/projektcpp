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

void ball::draw(float &xgracza)
{
	move(posx, posy, xgracza);
	pilka.setPosition(posx, posy, 20);
	pilka.drawFaces();
}

void ball::move(float &posx,float &posy,float &xgracza)
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
	if (posy <= -392 && posy >= -404 && posx>= (xgracza -60) && posx <= (xgracza +60)) //odbicie od gracza
	{
		cout << xgracza << endl;

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