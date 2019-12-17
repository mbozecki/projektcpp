#include "menu.h"
menu::menu()
{

}
void menu::setup()
{
	ofLoadImage(menutlo, "tlomenupng.png");

	punkty[0].x = -500 + 9999; punkty[0].y = -250 + 9999;
	punkty[1].x = 500 + 9999; punkty[1].y = -250 + 9999;
	punkty[2].x = 500 + 9999; punkty[2].y = 250 + 9999;
	punkty[3].x = -500 + 9999; punkty[3].y = 250 + 9999;



	menus1.loadModel("helio.obj");
	menus1.setScale(0.1, 0.1, 0.1);
	menus1.setPosition(9880, 9999, 250);

	menus2.loadModel("helio.obj");
	menus2.setScale(0.1, 0.1, 0.1);
	menus2.setPosition(10127, 9999, 250);

}
void menu::update()
{

}
void menu::draw()
{
	menutlo.draw(punkty[0], punkty[1], punkty[2], punkty[3]);
	menus1.drawFaces();
	menus2.drawFaces();

	if (u < 360)
	{
		menus1.setRotation(1, u, 0, 1, 0);
		menus2.setRotation(1, -u, 0, 1, 0);
		u = u + 1;
	}
	else
	{
		u = 0;
	}
}