#include <SFML/Graphics.hpp>
#include"Player.h"
#include"PatrollingEnemy.h"
#include"Potion.h"
#include"Floor.h"
#include"Pillar.h"
#include"Map.h"

using namespace sf;

int main() {

    RenderWindow window(VideoMode(1000, 1000), "Projet SFML 2");
    window.setFramerateLimit(120);
    Player* p = new Player(200, 400);
    Map map(p);
    map.loadMap("assets/map.txt");
    RectangleShape rect = RectangleShape(Vector2f(1000, 200));
    
    rect.setFillColor(Color::Black);
    rect.setPosition(0, 0);

    

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close(); 
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape)) { window.close(); }



        window.clear(Color::White);
        window.draw(rect);
        map.update(window);
        p->update(window, p->sprite);
        window.display();
    }

    return 0;
}