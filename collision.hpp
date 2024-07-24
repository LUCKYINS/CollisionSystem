#ifndef COLLISION
#define COLLISION
#include <iostream>
#include "vec.hpp"
#include <math.h>

class Shape2D{
    protected:
        int area = 1;
    public:
        int getArea()const{
            return area;
        }
};
class Circle:public Shape2D{
    private:
        int radius = 0;
    public:
        void setArea(){
            area = 3 * pow(radius, 2);
        }
        ~Circle() = default;
        Circle() = default;
        Circle(int R):radius(R){
            setArea();
        }
};
class Ellipse{//TODO

};
class Square{//TODO

};
class Rectangle{//TODO

};
class Triangle{//TODO
    
};

class StaticCollision{//TODO GET AREA
    
    private:
        const Shape2D shape;
        Vec2 Postion;
        
        
    public:
        ~StaticCollision() = default;
        StaticCollision(const Shape2D& S, Vec2& P):shape(S), Postion(P){}
        void createCollision();
        bool isCollied(StaticCollision & obj);
};

class DynamicCollision:StaticCollision{
    private:

    public:
        void stickToObject(){

        }
};
#endif