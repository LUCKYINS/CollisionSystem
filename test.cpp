#include <iostream>
#include "vec.hpp"
#include <unordered_set>
int main(){
    bool x = Vec2(2, 4) == Vec2(3,4);
    std::cout<<x;
}
