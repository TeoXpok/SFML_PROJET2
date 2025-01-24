#include "Floor.h"

Floor::Floor(int x, int y)  : Entity(x, y){

    if (!texture.loadFromFile("assets\\tiles\\floor.png")) {
        std::cerr << "Erreur : impossible de charger 'playersprite'" << std::endl;
    }
    sprite.setTexture(texture);
    /*sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);*/
    sprite.setScale(Vector2f(3.125, 3.125));

    sprite.setPosition(x, y);
}


void Floor::draw(RenderWindow& window) {
    window.draw(sprite);
}

void Floor::update(RenderWindow& window, Sprite spriteP){
    draw(window);
}