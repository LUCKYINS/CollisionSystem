#include <iostream>
#include <cmath>
#include "vec.hpp"
#include <math.h>
#include <set>

#ifndef COLLISION
#define COLLISION

// Shape2D (abstract class)
class Shape2D{
    protected:
        Vec2 centre = Vec2(0,0);
    public:
        ~Shape2D() = default;
        Shape2D() = default;
        Shape2D(Vec2 CENTRE): centre(CENTRE){}
        virtual Vec2 getCentre()const{
            return centre;
        };
};

// Circle

class Circle:public Shape2D{
    private:
        double radius = 1;
    public:
        ~Circle() = default;
        Circle() =int default;
        Circle(double RADIUS, Vec2 CENTRE):radius(RADIUS),Shape2D(CENTRE){
        }
};

// Ellipse

class Ellipse:public Shape2D{
    private:
        double A_axis=1;
        double B_axis=1;
    public:
        ~Ellipse() = default;
        Ellipse() = default;
        Ellipse(int A_AXIS, int B_AXIS, Vec2 CENTRE):A_axis(A_AXIS), B_axis(B_AXIS), Shape2D(CENTRE){
        }
};

// Rectangle & Square

class Rectangle:public Shape2D{ //TODO test collision between two Rectangle
    private:
        double width=1;
        double length=1;
    public:
        ~Rectangle() = default;
        Rectangle() = default;
        Rectangle(int WIDTH, int LENGTH, Vec2 CENTRE):width(WIDTH), length(LENGTH), Shape2D(CENTRE){
        }
        double getWidth(){
            return width;
        }
        double getLength(){
            return length;
        }

};

// Triangle

class Triangle:public Shape2D{
    private:
        double height;
        double base;
    public:
        ~Triangle() = default;
        Triangle() = default;
        Triangle(int HEIGHT, int BASE, Vec2 CENTRE):height(HEIGHT), base(BASE), Shape2D(CENTRE){
        }
};

// Collision

class StaticCollision{
    private:
        Shape2D shape;
    public:
        ~StaticCollision() = default;
        StaticCollision() = default;
        StaticCollision(Shape2D SHAPE):shape(SHAPE){}
};

class DynamicCollision:public StaticCollision{
    private:
    public:
        DynamicCollision(Shape2D SHAPE): StaticCollision(SHAPE){}
        void stickToObject(){
        }
};

// Container
class CollisionObjectContainer{
    private:
    public:
        ~CollisionObjectContainer() = default;
        CollisionObjectContainer()= default;
};

#endif
