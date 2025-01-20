#include <SFML/Graphics.hpp>
#include"Entity.h"
#include"Player.h"

using namespace sf;

int main() {

    RenderWindow window(VideoMode(800, 600), "Fenêtre SFML");
    window.setFramerateLimit(120);


    Player player = Player(50, 50);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close(); 
        }
        player.update(window);

        window.clear(Color::White);
        player.draw(window);
        window.display();
    }

    return 0;
}