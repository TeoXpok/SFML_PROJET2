#pragma once
#ifndef PATROLLINGENEMY_H
#define PATROLLINGENEMY_H
#include "Enemy.h"



using namespace sf;

class PatrollingEnemy : public Enemy
{
public:

    float vitesse;
    std::string paterne;

    PatrollingEnemy(int x, int y, std::string paterne);

    void update(RenderWindow& window, Sprite spriteP) override;
    void draw(RenderWindow& window) override;
    bool colisionplayer(Sprite spriteP) override;
    void patrouille();

};

#endif // !PATROLLINGENEMY_H
