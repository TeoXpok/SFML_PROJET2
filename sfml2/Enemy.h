#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"

using namespace sf;

class Enemy : public Entity
{
public:

    Enemy(int x, int y, float vitesse);

    float vitesse;

    virtual void colisionplayer(Sprite spriteP) = 0;


};


#endif // !ENEMY_H

