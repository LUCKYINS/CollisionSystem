#include <iostream>
#include <SFML/Graphics.hpp>
#include <unordered_set>
#include "vec.hpp"


const sf::Vector2f murv(double a, double v, double x){
        v = v + a;
        x = x + v + (1/2) * a;
        return sf::Vector2f(v, x);
}
const std::unordered_set<Vec2> getCollisionPositionSet(const sf::Vector2f& center, const sf::Vector2f& dimension){
    std::unordered_set<Vec2> collision;
    for (int x=0; x <= dimension.x; x++){
        for(int y=0; y<= dimension.y; y++){
            collision.insert(Vec2(x+center.x,y+center.y));
        }
    }
    return collision;
}