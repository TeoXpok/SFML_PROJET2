#include "Pillar.h"


Pillar::Pillar(int x, int y, Player* p) : p(p), Wall(x, y) {

    if (!texture.loadFromFile("assets\\tiles\\pillar.png")) {
        std::cerr << "Erreur : impossible de charger 'pillar'" << std::endl;
    }
    sprite.setTexture(texture);
    /*sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);*/
    sprite.setScale(Vector2f(3.125, 3.125));

    sprite.setPosition(x, y);
}


void Pillar::draw(RenderWindow& window) {
    window.draw(sprite);

}
void Pillar::colisionplayer(Sprite spriteP){
    sf::FloatRect rect1 = sprite.getGlobalBounds();
    sf::FloatRect rect2 = spriteP.getGlobalBounds();
    if (rect1.intersects(rect2)) {
        if (Keyboard::isKeyPressed(Keyboard::Q)) {
            p->x += p->vitesse+1;
        }
        if (Keyboard::isKeyPressed(Keyboard::Z)) {
            p->y += p->vitesse + 1;
        }
        if (Keyboard::isKeyPressed(Keyboard::S)) {
            p->y -= p->vitesse + 1;
        }
        if (Keyboard::isKeyPressed(Keyboard::D)) {
            p->x -= p->vitesse + 1;
        }
        
    }
    
}


void Pillar::update(RenderWindow& window, Sprite spriteP) {
    colisionplayer(spriteP);
    draw(window);
}

