
#include <cstdio>
#include <functional>
#include <iostream>
#include <cmath>
#include "vec.hpp"
#include <math.h>
#include <set>
#include <vector>

#ifndef COLLISION
#define COLLISION


// Shape2D (abstract class)
class Shape2D{
    protected:
        Vec2 centre = Vec2(0,0);
        bool dynamic = true;
    public:
        ~Shape2D() = default;
        Shape2D() = default;
        Shape2D(Vec2 CENTRE): centre(CENTRE){}
        Vec2 getCentre()const{return centre;}
        bool operator==(Shape2D & obj){return obj.centre == centre;}
};

// Circle

class Circle:public Shape2D{
    private:
        double radius = 1;
    public:
        ~Circle() = default;
        Circle() = default;
        Circle(double RADIUS, Vec2 CENTRE):radius(RADIUS),Shape2D(CENTRE){}
};

// Ellipse

class Ellipse:public Shape2D{
    private:
        double A_axis=1;
        double B_axis=1;
    public:
        ~Ellipse() = default;
        Ellipse() = default;
        Ellipse(int A_AXIS, int B_AXIS, Vec2 CENTRE):A_axis(A_AXIS), B_axis(B_AXIS), Shape2D(CENTRE){}
};

// Rectangle & Square

class Rectangle:public Shape2D{ //TODO test collision between two Rectangle
    private:
        double height=1;
        double width=1;
    public:
        ~Rectangle() = default;
        Rectangle() = default;
        Rectangle(int WIDTH, int HEIGHT, Vec2 CENTRE):width(WIDTH), height(HEIGHT), Shape2D(CENTRE){}
        double getWidth(){return width;}
        double getHeight(){return height;}
        void setCentre(Vec2 obj){centre = obj;}
        void setCentre(double x, double y){centre = Vec2(x, y);}
        void changeCentre(Vec2 obj){centre+=obj;}
        void changeCentre(double x, double y){centre += Vec2(x, y);}
        bool operator==(Rectangle & obj){return Shape2D::operator==(obj) && obj.height == height && obj.width == width;}
};

// Triangle

class Triangle:public Shape2D{
    private:
        double height;
        double base;
    public:
        ~Triangle() = default;
        Triangle() = default;
        Triangle(int HEIGHT, int BASE, Vec2 CENTRE):height(HEIGHT), base(BASE), Shape2D(CENTRE){}
};

// Container
class CollisionObjectContainer{
    private:
        std::vector<std::reference_wrapper<Rectangle>> collisionVector; // add refenceing of objects

    public:
        ~CollisionObjectContainer() = default;
        CollisionObjectContainer() = default;
        void addCollisionObject(Rectangle &obj){collisionVector.push_back(obj);}

        void checkCollision(){
            for (Rectangle &obj1 : collisionVector){
                for(Rectangle &obj2: collisionVector){

                    // Colliding for rect
                    bool colliding = obj1.getCentre().getX() - obj1.getWidth()/2 <= obj2.getCentre().getX() + obj2.getWidth()/2 &&
                    obj1.getCentre().getX() + obj1.getWidth()/2 >= obj2.getCentre().getX() - obj2.getWidth()/2&&
                    obj1.getCentre().getY() - obj1.getHeight()/2 <= obj2.getCentre().getY() + obj2.getHeight()/2&&
                    obj1.getCentre().getY() + obj1.getHeight()/2 >= obj2.getCentre().getY() - obj2.getHeight()/2;

                    if (!(obj1==obj2) && colliding){
                        printf("ok\n");
                        obj2.setCentre(0, 100);
                    }
                }
            }
        }
};

#endif
