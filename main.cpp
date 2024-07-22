#include <iostream>
#include <SFML/Graphics.hpp>
#include <unordered_set>
#include "vec.hpp"



const std::unordered_set<Vec2> getCollisionPositionSet(const sf::Vector2f& center, const sf::Vector2f& dimension){
    std::unordered_set<Vec2> collision;
    for (int x=0; x <= dimension.x; x++){
        for(int y=0; y<= dimension.y; y++){
            collision.insert(Vec2(x+center.x,y+center.y));
        }
    }
    return collision;
}

const sf::Vector2f murv(double a, double v, double x){
        v = v + a;
        x = x + v + (1/2) * a;
        return sf::Vector2f(v, x);
        
}


int main(){
    sf::RenderWindow window(sf::VideoMode(800, 500), "Collision");
    sf::CircleShape shape(50);
    sf::RectangleShape rec(sf::Vector2f(800, 50));

    rec.setPosition(0, 400);
    
    std::unordered_set<Vec2> collision = getCollisionPositionSet(rec.getPosition(),rec.getSize());
    double a = 0.0000001;
    double v = 0;
    double y = 0;

    while (window.isOpen()){
        sf::Event InputEvent;
        while (window.pollEvent(InputEvent)){
            if (InputEvent.type == InputEvent.Closed){
                window.close();
            }
        }
        // Collision
        //
        
        shape.setPosition(0, y);
        if (shape.getPosition().y > 200){
            if (collision.count(Vec2(shape.getPosition().x, shape.getPosition().y))){
                a = 0.1;
                v = 0;
            }

        }
        window.clear();
        window.draw(shape);
        window.draw(rec);
        window.display();

        v = v + a;
        y = y + v + (1/2) * a;
    }
    
    return 0;
}