#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <vector>

#include "Color.hpp"
#include "Engine.hpp"
#include "Mat3.hpp"
#include "primitives.hpp"
#include "Vec3.hpp"

enum ClippingType {
    CLIP_OUTER = 0,
    CLIP_INNER = 1
};

class Shape {
    public:
        ClippingType clippingType;
        Color color;

        double rotation;
        Vec3 position;
        Vec3 scale;

        std::vector<Vec3> points;
        std::vector<Vec3> points_transformed;

        Shape(ClippingType, Vec3 = Vec3(0.0f, 0.0f, 0.0f), double = 0.0f, Vec3 = Vec3(0.0f, 0.0f, 0.0f));
        Shape(std::vector<Vec3>, ClippingType, Vec3 = Vec3(0.0f, 0.0f, 0.0f), double = 0.0f, Vec3 = Vec3(0.0f, 0.0f, 0.0f));
        Shape(std::vector<Vec3>, Color, ClippingType, Vec3 = Vec3(0.0f, 0.0f, 0.0f), double = 0.0f, Vec3 = Vec3(0.0f, 0.0f, 0.0f));
        ~Shape();

        void updatePoints();
        void setTransform(Vec3, double, Vec3);

        void clipDrawLine(Engine *, Vec3, Vec3, std::vector<Shape> &, int, int &);
        void draw(Engine *, std::vector<Shape> &, int);
};

#endif
