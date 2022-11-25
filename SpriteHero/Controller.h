#pragma once
#include "Bullet.h"
#include "Calaveras.h"
#include <vector>
#include"Persona.h"
#include "MyForm.h"
#include <Windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
using namespace std;

class Controller {
public:
	vector<Bullet*>Bullets;
	vector<Calaveras*>enemies;
	vector<Persona*>hero;
	int numberOfEnemies;
	bool d1;
	bool d2;
	
public:
	Controller(int n, bool dp) {
		if (dp==true)
		{
			numberOfEnemies = n;
		}
		else
		{
			numberOfEnemies = 2 * n;
		}
	}

	~Controller(){}

	void createEnemies(int width, int height) {
		for (int i = 0; i < numberOfEnemies; i++)
		{
			Calaveras* e = new Calaveras(width, height, rand() % 2);
			enemies.push_back(e);
		}
	}
	void addBullet(Bullet* b) {
		Bullets.push_back(b);
	}
	void drawEveryThing(Graphics^ g, Bitmap^ bmpEnemy, Bitmap^ bmpBullet) {
		for (int i = 0; i < enemies.size(); i++)
		{
			enemies[i]->draw(g, bmpEnemy);
		}
		for (int i = 0; i < Bullets.size(); i++)
		{
			Bullets[i]->draw(g,bmpBullet);
		}
	}

	void moveEveryThing(Graphics^ g ) {
		for (int i = 0; i < enemies.size(); i++)
		{
			enemies[i]->move(g);
		}
		for (int i = 0; i < Bullets.size(); i++)
		{
			Bullets[i]->move(g);
		}
	}
	void collision(Graphics^ g) {
		int kills = 0;
		//verificar
		for (int i = 0; i < Bullets.size(); i++)
		{
			if (Bullets[i]->getX() <= 0 || Bullets[i]->getXWidth() >= g->VisibleClipBounds.Width ||
				Bullets[i]->getY() <= 0 || Bullets[i]->getYHeight() >= g->VisibleClipBounds.Height) {
				Bullets[i]->setVisibility(false);
				
			}
		}

		// colision bullet vs enemy
		for (int i = 0; i < enemies.size(); i++)
		{
			for (int j = 0; j < Bullets.size(); j++)
			{
				if (enemies[i]->getRectangle().IntersectsWith(Bullets[j]->getRectangle())) {
					enemies[i]->setVisibility(false);
					Bullets[j]->setVisibility(false);
					PlaySound((LPCWSTR)"explosion.wav", NULL, SND_ASYNC | SND_FILENAME);
					kills++;
				}
			}
		}
		
		//colision hero vs enemy
		
		
		//borrar
		for (int i = 0; i < Bullets.size(); i++)
		{
			if (!Bullets[i]->getVisibility()) { //if(Bullets[i]->getVisibility()==false)
				Bullets.erase(Bullets.begin() + i);
			}
		}

		for (int i = 0; i < enemies.size(); i++)
		{
			if (!enemies[i]->getVisibility()) {
				enemies.erase(enemies.begin() + i);
			}
		}

	}


};