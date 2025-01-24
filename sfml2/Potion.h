#pragma once
#ifndef POTION_H
#define POTION_H
#include "Item.h"
#include "Pillar.h"

class Potion : public Item
{
public:

	Player* p;


	Potion(int x, int y, Player* p);
	void interact(Sprite spriteP) override;
	void draw(RenderWindow& window) override;
	void update(RenderWindow& window, Sprite spriteP) override;

};

#endif // !Potion
