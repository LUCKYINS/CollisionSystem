#include <iostream>
#include <unordered_set>
#include "vec.hpp"


const Vec2 murv(double a, double v, double x){
        v = v + a;
        x = x + v + (1/2) * a;
        return Vec2(v, x);
}
const std::unordered_set<Vec2> getCollisionPositionSet(const Vec2& center, const Vec2& dimension){
    std::unordered_set<Vec2> collision;
    for (int x=0; x <= dimension.getX(); x++){
        for(int y=0; y<= dimension.getY(); y++){
            collision.insert(Vec2(x+center.getX(),y+center.getY()));
        }
    }
    return collision;
}
