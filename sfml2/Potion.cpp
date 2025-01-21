#include "Potion.h"

Potion::Potion(int x, int y) : Item(x, y){

    if (!texture.loadFromFile("assets\\potion_02a.png")) {
        std::cerr << "Erreur : impossible de charger 'potion'" << std::endl;
    }
}


void Potion::interact(Sprite spriteP) {
    sf::FloatRect rect1 = sprite.getGlobalBounds();
    sf::FloatRect rect2 = spriteP.getGlobalBounds();
};

void Potion::update(RenderWindow& window, Sprite spriteP) {

    interact(spriteP);
}

void Potion::draw(RenderWindow& window) {

    window.draw(sprite);
}