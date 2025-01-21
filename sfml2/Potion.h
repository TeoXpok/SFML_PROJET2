#pragma once
#ifndef POTION_H
#define POTION_H
#include "Item.h"


class Potion : public Item
{
public:

	Potion(int x, int y);
	void interact(Sprite spriteP) override;
	void draw(RenderWindow& window) override;
	void update(RenderWindow& window, Sprite spriteP) override;

};

#endif // !Potion
