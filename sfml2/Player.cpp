#include "Player.h"
#include <iostream>

Player::Player(int x, int y) : Entity(x, y) {

    if (!texture.loadFromFile("assets\\player.png")) {
        std::cerr << "Erreur : impossible de charger 'playersprite'" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
    sprite.setScale(Vector2f(5, 5));

    vitesse = 2;
}

void Player::update(RenderWindow& window){
    if (Keyboard::isKeyPressed(Keyboard::Q) && x - vitesse - sprite.getGlobalBounds().width > 0) {
        x += -vitesse;
    }
    if (Keyboard::isKeyPressed(Keyboard::Z) && y - vitesse - sprite.getGlobalBounds().height > 0) {
        y += -vitesse;
    }
    if (Keyboard::isKeyPressed(Keyboard::S) && y + vitesse + sprite.getGlobalBounds().height < window.getSize().y) {
        y += vitesse;
    }
    if (Keyboard::isKeyPressed(Keyboard::D) && x + vitesse + sprite.getGlobalBounds().width < window.getSize().x) {
        x += vitesse; 
    }
    sprite.setPosition(x, y);
}

void Player::draw(RenderWindow& window) {

    window.draw(sprite);
    

}