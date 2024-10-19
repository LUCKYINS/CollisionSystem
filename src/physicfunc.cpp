#include <iostream>
#include "vec.hpp"


const Vec2 murv(double a, double v, double x){
        v = v + a;
        x = x + v + (1.0/2) * a;
        return Vec2(v, x);
}
