
#ifndef VEC_HPP
#define VEC_HPP
#include <iostream>

class Vec2{
    /*
        * Proved a two dimensional vector
    */
    protected: // protected so it could be inherited but also private

        int x=0;
        int y=0;

    public:

        Vec2()= default;
        ~Vec2() = default;
        Vec2(int X, int Y):x(X), y(Y){};

        int getX() const{
        /*
            *Get the x member of the vector
        */
            return x;
        }

        int getY() const{
        /*
            *Get the y member of the vector
        */
            return y;
        }

        bool operator==(const Vec2& obj)const{
            return (obj.x == x) && (obj.y == y);
        }

        void operator+= (const Vec2& obj){
            x += obj.x;
            y += obj.y;
        }
        Vec2 operator+(const Vec2& obj2){
            return Vec2(obj2.x + x, obj2.y + y);
        }
};

class Vec3:public Vec2{
    /*
        *Proved a three dimensional vector
    */
    private:

        int z=0;

    public:

        Vec3() = default;
        ~Vec3() = default;

        Vec3(int Z, int X, int Y):Vec2(X,Y),z(Z){}; // Using Vec2 constructor
        Vec3(Vec2 OBJ, int Z): Vec2(OBJ.getX(), OBJ.getY()), z(Z){};

        int getZ()const{
            /*
                *Get the z member of the vector
            */
            return z;
        }

        bool operator==(const Vec3& obj)const{
            return Vec2::operator==(obj) && (obj.z == z); // Using Vec2 Operator==
        }
        void operator+=(const Vec3& obj){
            Vec2::operator+=(obj);
            z += obj.z;
        }
        Vec3 operator+(const Vec3& obj){
            return Vec3(Vec2::operator+(obj), z+obj.z);
        }
};

namespace std {
    template <> struct hash<Vec2> {
        std::size_t operator()(const Vec2 &obj) const {
            std::size_t h1 = std::hash<int>()(obj.getX());
            std::size_t h2 = std::hash<int>()(obj.getY());
            return h1 ^ (h2 << 1); // or use any other hash combination strategy
        }
    };
}
#endif
