#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <vector>

#include "Vec3.hpp"

class Shape {
    public:
        std::vector<Vec3> points;

        Shape();
        ~Shape();
};

#endif
