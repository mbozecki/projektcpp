#include "player.h"
using namespace std;

player::player()
{

}

void player::setup()
{
	tekstura.loadModel("Column22.3ds"); ////gracz
	tekstura.setScale(0.16, 0.16, 0.16);
	tekstura.setPosition(x, y, z);
	tekstura.setRotation(0, 90, 0, 0, 1);

}

void player::draw()
{
	tekstura.drawFaces();
}

void player::update()
{

}

void player::move(char q,float Xbox)
{
	if (q == 'a')
	{
		if (x > (Xbox+50)) x = x - 10;
		tekstura.setPosition(x, y, z);
	}

	else if (q == 'd')
	{
		if (x < (Xbox - 60)) x = x + 10;
		tekstura.setPosition(x, y, z);
	}

}

float player::getx()
{
	return player::x;

}
float player::gety()
{
	return player::y;
}