#include <SFML/Graphics.hpp>
#include"Player.h"
#include"PatrollingEnemy.h"
#include"Potion.h"

using namespace sf;

int main() {

    RenderWindow window(VideoMode(800, 600), "Projet SFML 2");
    window.setFramerateLimit(120);


    Player player = Player(50, 50);
    PatrollingEnemy z = PatrollingEnemy(200, 200, "ZZZZZZZZZZ           QQQQQQQQQQ           SSSSSSSSSS           DDDDDDDDDD");
    Potion p = Potion(500, 500);



    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close(); 
        }


        player.update(window, player.sprite);
        z.update(window, player.sprite);
        p.update(window, player.sprite);


        window.clear(Color::White);
        player.draw(window);
        z.draw(window);
        p.draw(window);

        window.display();
    }

    return 0;
}