#pragma once
#ifndef ENTITY_H
#define ENTITY_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
using namespace sf;

class Entity
{

public:

    int x;
    int y;
    Sprite sprite;
    Texture texture;

    Entity(int x, int y);
    virtual void update(RenderWindow& window, Sprite spriteP) = 0;
    virtual void draw(RenderWindow& window) = 0;

};

#endif // !ENTITY_H
