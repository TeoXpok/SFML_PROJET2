#include "PatrollingEnemy.h"
using namespace std;
using namespace sf;


PatrollingEnemy::PatrollingEnemy(int x, int y, string paterne) : paterne(paterne), Enemy(x, y, vitesse) {

    if (!texture.loadFromFile("assets\\Zombos1.png")) {
        std::cerr << "Erreur : impossible de charger 'Zombos2'" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setScale(Vector2f(2, 2));
    sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
    vitesse = 1;
}


bool PatrollingEnemy::colisionplayer(Sprite spriteP) {
    sf::FloatRect rect1 = sprite.getGlobalBounds();
    sf::FloatRect rect2 = spriteP.getGlobalBounds();
    return rect1.intersects(rect2);
};

void PatrollingEnemy::patrouille(){
    char first = paterne.front();
    paterne.erase(paterne.begin());
    paterne.push_back(first);
    switch (first)
    {
    case('Z'):
        y -= 1;
        break;
    case('Q'):
        x -= 1;
        break;
    case('S'):
        y += 1;
        break;
    case('D'):
        x += 1;
        break;
    default:
        break;
    }
}


void PatrollingEnemy::update(RenderWindow& window, Sprite spriteP) {
    patrouille();
    colisionplayer(spriteP);
    sprite.setPosition(x, y);
    draw(window);
}


void PatrollingEnemy::draw(RenderWindow& window) {

    window.draw(sprite);
}