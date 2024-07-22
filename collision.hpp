#ifndef COLLISION
#define COLLISION
#include <iostream>


class StaticCollision{
    private:
        std::string shape;
        
    public:
        void createCollision(){

        }
        bool isCollied(StaticCollision & obj){

        }
};

class DynamicCollision:StaticCollision{
    private:

    public:
        void stickToObject(){

        }
};
#endif