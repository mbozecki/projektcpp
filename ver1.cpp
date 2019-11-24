#include "stdafx.h"
#include <GL/glut.h>
#include<iostream>
#include <stdlib.h>
#include "soil.h"
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>
// Deklaracje funkcji, ktore beda uzyte do obslugi roznych zdarzen.
void OnRender();
void OnReshape(int, int);
// Punkt wejscia do programu.


float Xgracza = 0;

void keyPressed(unsigned char key, int x, int y)
{
	if (key == 'a')
	{ 
		std::cout << "elo";
		Xgracza = Xgracza - 0.05;
		if (Xgracza < -3)
		{
			Xgracza = 0;
		}
	}

	
	if (key == 'd')
	{
		Xgracza = Xgracza + 0.05;
		if (Xgracza > 3)
		{
			Xgracza = 0;
		}
	}
}

int main(int argc, char * argv[])
{

	// Inicjalizacja biblioteki GLUT. Nalezy przekazac parametry
	// wywolania programu.
	glutInit(&argc, argv);

	// Ustawienie parametrow okna i kontekstu OpenGL.

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(1024, 768);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH); // bufor klatki w formacie RGBA, double-buffered, z buforem glebokosci
	glutKeyboardFunc(keyPressed); //funkcja kontrolujaca klawisze
	// Utworzenie wlasciwego okna i nadanie mu tytulu.
	glutCreateWindow("Projekt CPP czesc 1");

	// Ustawienie funkcji Render() jako tej, ktora jest wykonywana
	// kazdorazowo gdy potrzeba przerysowac zawartosc okna.
	glutDisplayFunc(OnRender);
	glutReshapeFunc(OnReshape);

	// Wlaczenie testu glebokosci.
	glEnable(GL_DEPTH_TEST);

	// Rozpoczecie wykonywania petli glownej. Od tego momentu
	// wplyw na przebieg dzialania programu maja wylacznie zarejestrowane
	// uprzednio callbacki.
	glutMainLoop();

	return 0;
}

// Licznik klatek - uzyteczny przy prostym ruchu kamery.
int frame = 0;
float posx = 0.00;
float posy = 0.00;

int v = 0.01;//predkosc 


// Callback przerysowujacy klatke.
void OnRender() {

	glutKeyboardFunc(keyPressed);
	// Wyczysc zawartosc bufora koloru i glebokosci.
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Wybor macierzy, ktora od tej pory bedziemy modyfikowac
	// - macierz Modelu/Widoku.
	glMatrixMode(GL_MODELVIEW);

	// Zaladowanie macierzy jednostkowej.
	glLoadIdentity();

	// Przesuniecie swiata (przeciwienstwo przesuniecia kamery).
	glTranslatef(0.0f, 0.0f, -13.0f);

	// Obrot kamery
	//glRotatef(frame, 0.0f, 1.0f, 0.0f);
	glRotatef(0, 1.0f, 0.0f, 0.0f);


	// Rysowanie obiektow na scenie.

	// Prostopadloscian/brz
	glColor3f(0.1f, 0.0f, 0.1f);
	glPushMatrix();
		glTranslatef(0.0f, 0.5f, 0.0f);
		glScalef(7.0f, 10.0f, 0.5f);
		glutSolidCube(1.00f);
	glPopMatrix();	


	// Kulka
	glColor3f(0.0f, 1.0f, 0.0f);
	glPushMatrix();
		glTranslatef(posx, posy, 0.8f);
		glutSolidSphere(.2f, 24, 24);
	glPopMatrix();

	// gracz
	glColor3f(1.0f, 0.0f, 0.0f);
		glPushMatrix();
	glTranslatef(Xgracza, -3.5f, 0.0f);
	glScalef(1.0f, .5f, 1.5f);
	glutSolidCube(1.00f);
		glPopMatrix();

	if (posx < 3)
	{
		posx = 0.01*frame;
		

	}
	else
	{
		posx = posx - 0.1;
	}
	
	if (posy < 10)
	{
		posy = 0.005 * frame;
	}
	// Jesli instrukcje w danej implementacji OpenGL byly buforowane,
	// w tym momencie bufor zostanie oprozniony a instrukcje wykonane.
	glFlush();

	// Zamien front-buffer z back-bufferem (double buffering).
	glutSwapBuffers();

	// Nakaz wyswietlic kolejna klatke.
	glutPostRedisplay();

	// Inkrementacja licznika klatek.
	frame++;

}

// Callback obslugujacy zmiane rozmiaru okna.
void OnReshape(int width, int height) {
	// Wybor macierzy - macierz Projekcji.
	glMatrixMode(GL_PROJECTION);

	// Zaladowanie macierzy jednostkowej.
	glLoadIdentity();

	// Okreslenie obszaru renderowania - caly obszar okna.
	glViewport(0, 0, width, height);

	// Chcemy uzyc kamery perspektywicznej o kacie widzenia 60 stopni
	// i zasiegu renderowania 0.01-100.0 jednostek.
	gluPerspective(60.0f, (float) width / height, .01f, 100.0f);
}
