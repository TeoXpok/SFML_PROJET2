#pragma once
#ifndef PILLAR_H
#define PILLAR_H
#include "Wall.h"
#include "Player.h"

class Pillar : public Wall
{
public :

	Player* p;

	Pillar(int x, int y, Player* p);
	void update(RenderWindow& window, Sprite spriteP) override;
	void draw(RenderWindow& window) override;
	void colisionplayer(Sprite spriteP);
};


#endif // !PILLAR_H


