#include <SFML/Graphics.hpp>
#include"Player.h"
#include"PatrollingEnemy.h"
#include"Potion.h"
#include"Floor.h"

using namespace sf;

int main() {

    RenderWindow window(VideoMode(1000, 1000), "Projet SFML 2");
    
    window.setFramerateLimit(120);

    Floor f = Floor(500, 500);

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
        f.draw(window);
        window.display();
    }

    return 0;
}