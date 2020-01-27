#include "menu.h"
menu::menu()
{

}
void menu::setup()
{
	ofLoadImage(menutlo, "nowagraselected.png"); //zaladownie obrazka poczatkowego w menu
	ofLoadImage(menutlodol, "jakgracselected.png"); //zaladowanie opcji drugiej
	ofLoadImage(menuopcje, "kontrolspng.png"); //wejscie w 'jak grac?'
	ofLoadImage(koniec, "gameover.jpg"); //koniec gry

	punkty[0].x = -500 + 9999; punkty[0].y = -250 + 9999;
	punkty[1].x = 500 + 9999; punkty[1].y = -250 + 9999;
	punkty[2].x = 500 + 9999; punkty[2].y = 250 + 9999;
	punkty[3].x = -500 + 9999; punkty[3].y = 250 + 9999;

	menus1.loadModel("helio.obj"); //obracajace sie figurki w menu
	menus1.setScale(0.1, 0.1, 0.1);
	menus1.setPosition(9880, 9949, 250);

	menus2.loadModel("helio.obj"); //obracajace sie figurki w menu
	menus2.setScale(0.1, 0.1, 0.1);
	menus2.setPosition(10127, 9949, 250);

}
void menu::update()
{

}
void menu::draw()
{
	if (menunawigator == 1)
	{
		menutlo.draw(punkty[0], punkty[1], punkty[2], punkty[3]);
	}
	if (menunawigator == 0)
	{
		menutlodol.draw(punkty[0], punkty[1], punkty[2], punkty[3]);
	}
	if (menunawigator == 2)
	{
		menuopcje.draw(punkty[0], punkty[1], punkty[2], punkty[3]);
	}

	

	menus1.drawFaces();
	menus2.drawFaces();

	if (u < 360) // rotacja figurek
	{
		menus1.setRotation(1, u, 0, 1, 0);
		menus2.setRotation(1, -u, 0, 1, 0);
		u = u + 1;
	}
	else
	{
		u = 0;
	}

	menus1.setRotation(2,180, 0, 0,1);
	menus2.setRotation(2, 180, 0, 0 , 1);
}

void menu::endgame()
{
	koniec.draw(punkty[0], punkty[1], punkty[2], punkty[3]);
	
}