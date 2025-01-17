#include <SFML/Graphics.hpp>
using namespace sf;

class Entity 
{

public:

    int x;
    int y;
    Sprite sprite;

    Entity(int x, int y, Sprite sprite) : x(x), y(y), sprite(sprite) {}
    virtual void update() = 0;
    virtual void draw(RenderWindow& window) = 0;
    
};

class Player : public Entity
{
public:
    Sprite sprite;
    Player(int x, int y) : Entity(x, y, sprite) {}
    void update() override {
        if (Keyboard::isKeyPressed(Keyboard::Q)) {
            x += -1;
        }
        if (Keyboard::isKeyPressed(Keyboard::Z)) {
            y += -1;
        }
        if (Keyboard::isKeyPressed(Keyboard::S)) {
            y += 1;
        }
        if (Keyboard::isKeyPressed(Keyboard::D)) {
            x += 1;
        }
    }

    void draw(RenderWindow& window) {


    }

};

int main() {
    // Création de la fenêtre
    sf::RenderWindow window(sf::VideoMode(800, 600), "Fenêtre SFML");

    // Création d'un cercle
    sf::CircleShape shape(50); // Rayon de 50 pixels
    shape.setFillColor(sf::Color::Green);

    // Boucle principale
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close(); // Fermer la fenêtre
        }

        // Effacer la fenêtre
        window.clear();
        // Dessiner la forme
        window.draw(shape);
        // Afficher le contenu
        window.display();
    }

    return 0;
}