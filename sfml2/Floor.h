#pragma once
#ifndef FLOOR_H
#define FLOOR_H
#include "Tile.h"

class Floor : public Tile
{
public:
	Floor(int x, int y);
	void draw(RenderWindow& window);
};


#endif // !FLOOR_H