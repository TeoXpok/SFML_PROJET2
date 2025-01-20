#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "Entity.h"


using namespace sf;

class Player : public Entity
{
public:
    

    
    Player(int x, int y);
    
    
    void update(RenderWindow& window) override;

    void draw(RenderWindow& window) override;

}; 




#endif // !PLAYER_H