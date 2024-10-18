#include <iostream>
#ifndef VEC_HPP
#define VEC_HPP


class Vec2{
    /*
        * Proved a two dimensional vector
    */
    protected: // protected so it could be inherited but also private
        double x=0;
        double y=0;
    public:
        Vec2()= default;
        ~Vec2() = default;
        Vec2(double X, double Y):x(X), y(Y){};

        double getX() const{return x;}

        double getY() const{return y;}

        bool operator==(const Vec2& obj)const{return (obj.x == x) && (obj.y == y);}

        void operator+= (const Vec2& obj){
            x += obj.x;
            y += obj.y;
        }
        Vec2 operator+(const Vec2& obj2)const{return Vec2(obj2.x + x, obj2.y + y);}
};

class Vec3:public Vec2{
    /*
        *Proved a three dimensional vector
    */
    private:
        double z=0;
    public:
        Vec3() = default;
        ~Vec3() = default;

        Vec3(double Z, double X, double Y):Vec2(X,Y),z(Z){}; // Using Vec2 constructor
        Vec3(Vec2 OBJ, double Z): Vec2(OBJ.getX(), OBJ.getY()), z(Z){};

        double getZ()const{return z;}

        bool operator==(const Vec3& obj)const{return Vec2::operator==(obj) && (obj.z == z);} // Using Vec2 Operator==
        void operator+=(const Vec3& obj){
            Vec2::operator+=(obj);
            z += obj.z;
        }
        Vec3 operator+(const Vec3& obj)const{return Vec3(Vec2::operator+(obj), z+obj.z);}
};
namespace std {
    template <> struct hash<Vec2> {
        std::size_t operator()(const Vec2 &obj) const {
            std::size_t h1 = std::hash<double>()(obj.getX());
            std::size_t h2 = std::hash<double>()(obj.getY());
            return h1 ^ (h2 << 1); // or use any other hash combination strategy
        }
    };
}
#endif
