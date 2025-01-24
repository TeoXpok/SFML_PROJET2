#pragma once
#ifndef FLOOR_H
#define FLOOR_H
#include "Entity.h"

class Floor : public Entity
{
public:
	Floor(int x, int y);

	void update(RenderWindow& window, Sprite spriteP) override;
	void draw(RenderWindow& window) override;
	
};


#endif // !FLOOR_H