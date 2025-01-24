#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"


using namespace sf;

class Player : public Entity
{
public:

    float vitesse;
    bool boosted = false;
    Clock speedClock;
    
    Player(int x, int y);

    void update(RenderWindow& window, Sprite spriteP) override;
    void draw(RenderWindow& window) override;
    void speedboost();
}; 




#endif // !PLAYER_H