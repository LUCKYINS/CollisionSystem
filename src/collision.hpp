#include <iostream>
#include <cmath>
#include "vec.hpp"
#include <set>
#include <vector>

#ifndef COLLISION
#define COLLISION

enum class Shape2D{
  Rect,Tri,Cir,Elli
};

// Circle
class Circle{
    protected:
        double radius = 1;
    public:
        ~Circle() = default;
        Circle() = default;
        Circle(double RADIUS):radius(RADIUS){}
};

// Ellipse
class Ellipse{
    protected:
        double A_axis=1;
        double B_axis=1;
    public:
        ~Ellipse() = default;
        Ellipse() = default;
        Ellipse(int A_AXIS, int B_AXIS, Vec2 CENTRE):A_axis(A_AXIS), B_axis(B_AXIS){}
};

// Triangle
class Triangle{
    protected:
        double height;
        double base;
    public:
        ~Triangle() = default;
        Triangle() = default;
        Triangle(int HEIGHT, int BASE, Vec2 CENTRE):height(HEIGHT), base(BASE){}
};

// Rectangle & Square
class Rectangle{
    protected:
        double length=1;
        double width=1;
    public:
        ~Rectangle() = default;
        Rectangle() = default;
        Rectangle(int WIDTH, int LENGTH):width(WIDTH), length(LENGTH){}
        double getWidth()const{return width;}
        double getLength()const{return length;}
        bool operator==(Rectangle & obj)const{return obj.length == length && obj.width == width;}
};

//Shape2DCollision (replace Shape2D)
class Shape2DCollision: public Rectangle, Triangle, Ellipse, Circle{
    private:
        Vec2 centre = Vec2(0,0);
        //bool dynamic = true;
        Shape2D shape;

    public:
        ~Shape2DCollision() = default;
        Shape2DCollision() = default;

        Shape2DCollision(Rectangle OBJ, Vec2 CENTRE): Rectangle(OBJ),centre(CENTRE){shape = Shape2D::Rect;} // To continu

        Vec2 getCentre()const{return centre;}
        void setCentre(Vec2 obj){centre = obj;}
        void setCentre(double x, double y){centre = Vec2(x, y);}
        void changeCentre(Vec2 obj){centre+=obj;}
        void changeCentre(double x, double y){centre += Vec2(x, y);}

        Shape2D getShape()const{return shape;}

        bool operator==(Shape2DCollision & obj)const{
            if (obj.getShape() == Shape2D::Rect &&  shape==Shape2D::Rect){
                return obj.centre == centre && Rectangle::operator==(obj) ;
            }
            return false;
        }// TO CONTINUE
};

// Container
class CollisionObjectContainer{
    private:
        std::vector<std::reference_wrapper<Shape2DCollision>> collisionVector; // add refenceing of objects
        bool isColliding(Shape2DCollision &obj1, Shape2DCollision &obj2)const{
            if (obj1.getShape() == Shape2D::Rect  && obj2.getShape() == Shape2D::Rect){
                // Colliding for rect/rect
                bool colliding = obj1.getCentre().getX() - obj1.getWidth()/2 <= obj2.getCentre().getX() + obj2.getWidth()/2 &&
                obj1.getCentre().getX() + obj1.getWidth()/2 >= obj2.getCentre().getX() - obj2.getWidth()/2&&
                obj1.getCentre().getY() - obj1.getLength()/2 <= obj2.getCentre().getY() + obj2.getLength()/2&&
                obj1.getCentre().getY() + obj1.getLength()/2 >= obj2.getCentre().getY() - obj2.getLength()/2;
                return colliding;
            }
            return false;
        }

    public:
        ~CollisionObjectContainer() = default;
        CollisionObjectContainer() = default;
        void addCollisionObject(Shape2DCollision &obj){collisionVector.push_back(obj);}

        void checkCollision(){
            for (Shape2DCollision &obj1 : collisionVector){
                for(Shape2DCollision &obj2: collisionVector){
                    if (!(obj1==obj2) && isColliding(obj1, obj2)){
                    }
                }
            }
        }
};

#endif
