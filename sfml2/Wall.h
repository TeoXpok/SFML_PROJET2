#pragma once
#ifndef WALL_H
#define WALL_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "Entity.h"


using namespace sf;

class Wall : public Entity{
public:

	Wall(int x, int y);
	virtual void colisionplayer(Sprite spriteP) = 0;

};
#endif // !TILE_H
