#include "Potion.h"

Potion::Potion(int x, int y) : Item(x, y){

    if (!texture.loadFromFile("assets\\items\\potion_02a.png")) {
        std::cerr << "Erreur : impossible de charger 'potion'" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);

}


void Potion::interact(Sprite spriteP) {
    sf::FloatRect rect1 = sprite.getGlobalBounds();
    sf::FloatRect rect2 = spriteP.getGlobalBounds();
};

void Potion::update(RenderWindow& window, Sprite spriteP) {
    
    interact(spriteP);
    sprite.setPosition(x, y);

}

void Potion::draw(RenderWindow& window) {

    window.draw(sprite);
}