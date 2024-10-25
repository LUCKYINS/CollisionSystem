#include <SDL2/SDL_stdinc.h>
#include <cmath>
#include "vec.hpp"
#include <cstdio>
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
        bool pointInRectangle(Vec2 origin)const{
            bool leftlimit = origin.getX()> _origin.getX() - _width/2;
            bool rightlimit = origin.getX()<_origin.getX() + _width/2;
            bool uplimit = origin.getY()> _origin.getY() - _length/2;
            bool downlimit = origin.getY()<_origin.getY() + _length/2;
            return leftlimit && rightlimit && uplimit && downlimit;
        }
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
        Cell(Uint16 SCALE, Vec2& ORIGIN, Vec3& COLOR):_scale(SCALE), _origin(ORIGIN), _color(COLOR){};
        Cell(Uint16 SCALE, int x, int y, Uint8 r, Uint8 g, Uint8 b):_scale(SCALE), _origin(x, y), _color(r, g, b){}
        Cell(Uint16 SCALE, Vec2 ORIGIN):_scale(SCALE), _origin(ORIGIN){}
        Cell(Uint16 SCALE, int x, int y):_scale(SCALE), _origin(x, y){}
        // Destructors
        ~Cell()= default;

        //Setter
        void cellOn(){_on=true;}
        void cellOff(){_on=false;}
        void setCellColor(Uint8 r,Uint8  g,Uint8 b){_color = Vec3(r, g,b);}
        void setCellColor(Vec3 color){_color = color;}
        void setOrigin(int x, int y){_origin = Vec2(x, y);}
        void setOrigin(Vec2 origin){_origin = origin;}
        void setScale(Uint16 scale){_scale = scale;}

        //Getter
        Vec3 getCellColor()const{return _color;}
        Vec2 getOrigin()const{return _origin;}
        Uint16 getScale()const{return _scale;}
        bool isOn()const{return _on;}
};
typedef std::vector<Cell> cellsVector_t;

class GridLayer{//TODO cell scale
    private:
        Uint16 _width = 1, _height = 1,_cell_scale = 1;
        Uint32 _dimension = 1;
        cellsVector_t _cell_vector = {};
    public:
        GridLayer() = default;
        ~GridLayer() = default;
        GridLayer(Uint16 WIDTH, Uint16 HEIGHT):_width(WIDTH), _height(HEIGHT), _dimension(WIDTH*HEIGHT){
            for (Uint32 i = 0; i < _dimension; ++i){
                _cell_vector.emplace_back(Cell{_cell_scale, Vec2(i%_width,i/_width)}); // Transform to unordered set
            }
        }

        //Getter
        cellsVector_t& getCellsVector(){return _cell_vector;}
        Uint32 getDimension()const{return _dimension;}
        Uint16 getWidth()const{return _width;}
        void allCellOff(){
            for (Cell& i: _cell_vector){
                i.cellOff();
            }
        }

};
#endif
