#include <iostream>
#include "vec.hpp"
#include <math.h>
#include <set>

#ifndef COLLISION
#define COLLISION

class Shape2D{
    protected:
        int area = 1;
        std::set<Vec2> outerLayer;

    public:
        int getArea()const{
            return area;
        };
};
class Circle:public Shape2D{
    private:
        int radius = 1;
    public:
        void setArea(){
            area = M_PI * pow(radius, 2);
        }
        ~Circle() = default;
        Circle() = default;
        Circle(int RADIUS):radius(RADIUS){
            setArea();
        }
};
class Ellipse:public Shape2D{
    private:
        int A_axis=1;
        int B_axis=1;
    public:
        void setArea(){
            area = M_PI * A_axis * B_axis;
        }
        ~Ellipse() = default;
        Ellipse() = default;
        Ellipse(int A_AXIS, int B_AXIS):A_axis(A_AXIS), B_axis(B_AXIS){
            setArea();
        }
};
class Square:public Shape2D{
    private:
        int side = 1;
    public:
        void setArea(){
            area = side * side;
        }
        ~Square() = default;
        Square() = default;
        Square(int SIDE):side(SIDE){
            setArea();
        }

};
class Rectangle:public Shape2D{
    private:
        int width=1;
        int length=1;
    public:
        void setArea(){
            area = width * length;
        }
        ~Rectangle() = default;
        Rectangle() = default;
        Rectangle(int WIDTH, int LENGTH ):width(WIDTH), length(LENGTH){
            setArea();
        }
};
class Triangle:public Shape2D{
    private:
        int height;
        int base;
    public:
        void setArea(){
            area = height * base / 2;
        }
        ~Triangle() = default;
        Triangle() = default;
        Triangle(int HEIGHT, int BASE ):height(HEIGHT), base(BASE){
            setArea();
        }
};

class StaticCollision{//TODO createCollision
    private:
        const Shape2D shape;
        const Vec2 Postion;

    public:
        ~StaticCollision() = default;
        StaticCollision(const Shape2D& S, Vec2& P):shape(S), Postion(P){}
        void createCollision();
        bool isCollied(StaticCollision& obj);
};

class DynamicCollision:StaticCollision{
    private:

    public:
        void stickToObject(){

        }
};
class Container{// TODO contain the collision shape and sf shape

};
#endif
