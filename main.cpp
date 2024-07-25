#include <iostream>
#include <SFML/Graphics.hpp>
#include <unordered_set>
#include "vec.hpp"

sf::RenderWindow window(sf::VideoMode(800, 500), "Collision");
sf::RectangleShape square(sf::Vector2f(50, 50));
sf::RectangleShape rec(sf::Vector2f(800, 50));
void motion(){// TODO for object in motion

}
void animation(){// TODO when frame changes
        window.clear();
        window.draw(square);
        window.draw(rec);
        window.display();
}

int main(){
    rec.setPosition(0, 400);
    double a = 0.000001;
    double v = 0;
    double y = 0;

    while (window.isOpen()){
        sf::Event InputEvent;
        while (window.pollEvent(InputEvent)){
            if (InputEvent.type == InputEvent.Closed){
                window.close();
            }
        }
        square.setPosition(0, y);
        animation();
        v = v + a;
        y = y + v + (1/2) * a;
    }
    return 0;
}