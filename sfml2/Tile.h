#pragma once
#ifndef TILE_H
#define TILE_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using namespace sf;

class Tile {
public:
	int x;
	int y;

	Sprite sprite;
	Texture texture;


	Tile(int x, int y);
	virtual void draw(RenderWindow& window) = 0;

};
#endif // !TILE_H
