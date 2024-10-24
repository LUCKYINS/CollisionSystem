#include <SDL2/SDL_stdinc.h>
#include <cmath>
#include "vec.hpp"
#include <vector>

#ifndef COLLISION
#define COLLISION


// Circle
class Circle{
    protected:
        int radius = 1;
        Vec2 origin = Vec2(0,0);
    public:
        ~Circle() = default;
        Circle() = default;
        Circle(int RADIUS):radius(RADIUS){}
        bool inCircle(int i, int radius)const{return true;}//TODO
};

// Rectangle & Square
class Rectangle{
    protected:
        int _length=1;
        int _width=1;
        Vec2 _origin = Vec2(0,0);
    public:
        ~Rectangle() = default;
        Rectangle() = default;
        Rectangle(int WIDTH, int LENGTH, Vec2 ORIGIN):_width(WIDTH), _length(LENGTH), _origin(ORIGIN){}
        int getWidth()const{return _width;}
        int getLength()const{return _length;}
        bool inRectangle()const{return true;}//TODO
        bool operator==(Rectangle & obj)const{return obj._length == _length && obj._width == _width;}
};

class Cell{
    private:
        Uint16 _scale = 1;
        bool _on = false;
        Vec2 _origin = Vec2(0, 0);
        Vec3 _color= Vec3(0, 0, 0);
    public:
        // Constructors
        Cell() = default;
        Cell(Uint16 SCALE, Vec2 ORIGIN, Vec3 COLOR):_scale(SCALE), _origin(ORIGIN), _color(COLOR){};
        Cell(Uint16 SCALE, int x, int y, Uint8 r, Uint8 g, Uint8 b):_scale(SCALE), _origin(x, y), _color(r, g, b){}
        Cell(Uint16 SCALE, Vec2 ORIGIN):_scale(SCALE), _origin(ORIGIN){}
        Cell(Uint16 SCALE, int x, int y):_scale(SCALE), _origin(x, y){}
        // Destructors
        ~Cell()= default;

        //Setter
        void CellOn(){_on=true;}
        void CellOf(){_on=false;}
        void setCellColor(Uint8 r,Uint8  g,Uint8 b){_color = Vec3(r, g,b);}
        void setCellColor(Vec3 color){_color = color;}
        void setOrigin(int x, int y){_origin = Vec2(x, y);}
        void setOrigin(Vec2 origin){_origin = origin;}
        void setScale(Uint16 scale){_scale = scale;}

        //Getter
        Vec3 setCellColor()const{return _color;}
        Vec2 setOrigin()const{return _origin;}
        Uint16 setScale()const{return _scale;}
};

typedef std::vector<std::reference_wrapper<Cell>> refCellsVector_t;

class GridLayer{//TODO cell scale
    private:
        Uint16 _width = 1, _height = 1,_cell_scale = 1, _dimension = _width*_height;
        refCellsVector_t cellsVector = {};
    public:
        GridLayer() = default;
        ~GridLayer() = default;
        GridLayer(Uint16 WIDTH, Uint16 HEIGHT):_width(WIDTH), _height(HEIGHT){
            for (int i = 0; i < _dimension; ++i){
                Cell c = Cell(_cell_scale, Vec2(i%_width, i/_height));
                cellsVector.push_back(c);
            }
        }

        //Getter
        refCellsVector_t getCellsVector()const{return cellsVector;}
        Uint16 getDimension()const{return _dimension;}
        Uint16 getWidth()const{return _width;}

};
#endif
