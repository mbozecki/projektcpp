#include "ball.h"
#include "math.h"
#include <stdlib.h>     // wartosc abs
ball::ball()
{

}

void ball::setup()
{
	pilka.loadModel("toto.dae");
	pilka.setScale(0.06, 0.06, 0.06);
	pilka.setPosition(posx,posy, 20);
}

void ball::update()
{

}

void ball::draw(float &xgracza)
{
	if (started == true)
	{
		move(posx, posy, xgracza);
	}
	else
	{
		gluetoplayer(posx, posy, xgracza);
	}
	
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
		vy = -4; 
		if (vx <= 0)
		{
			vx = -4;
		}
		else
		{
			vx = 4;
		}

		if ((posx - xgracza) < 0 && (vx>0))
		{
			vx = -vx * abs((posx - xgracza) / 50);
		}
		else if ((posx - xgracza) > 0 && (vx<0))
		{
			vx = -vx * abs((posx - xgracza) / 50);
		}
		else
		{
			vx = vx * abs((posx - xgracza) / 50);
		}
		
		vy = sqrt(abs((vx * vx) - 32));

	}

	if (posy > 450)
	{
		vy = -vy;
		posy += vy;
	}
	else
	{
		posy += vy;
		cout << vy << endl;
	}
	if (vy >= 4.4)
	{
		vy = 4;
	}
}

void ball::gluetoplayer(float &posx, float &posy, float &xgracza)
{
	posy = -384;
	posx = xgracza;

}