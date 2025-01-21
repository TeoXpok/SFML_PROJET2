#pragma once
#ifndef ITEM_H
#define ITEM_H
#include "Entity.h"

using namespace sf;

class Item : public Entity
{
public:

    Item(int x, int y);

    virtual void interact(Sprite spriteP) = 0;

};



#endif // !ITEM_H
