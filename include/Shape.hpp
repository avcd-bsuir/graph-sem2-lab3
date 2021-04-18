#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <vector>

#include "Color.hpp"
#include "Engine.hpp"
#include "primitives.hpp"
#include "Vec3.hpp"

class Shape {
    public:
        std::vector<Vec3> points;
        std::vector<Color> colors;
        bool closed;

        Shape(bool = true);
        Shape(std::vector<Vec3>, bool = true);
        Shape(std::vector<Vec3>, std::vector<Color>, bool = true);
        ~Shape();

        void draw(Engine *);
        void draw(Engine *, Color);
};

#endif
