#include "Shape.hpp"

Shape::Shape(ClippingType clippingType, Vec3 position, double rotation, Vec3 scale) : color(Color(255, 255, 255)), clippingType(clippingType) {
    this->setTransform(position, rotation, scale);
}

Shape::Shape(std::vector<Vec3> points, ClippingType clippingType, Vec3 position, double rotation, Vec3 scale) : points(points), color(Color(255, 255, 255)), clippingType(clippingType) {
    this->setTransform(position, rotation, scale);
}

Shape::Shape(std::vector<Vec3> points, Color color, ClippingType clippingType, Vec3 position, double rotation, Vec3 scale) : points(points), color(color), clippingType(clippingType) {
    this->setTransform(position, rotation, scale);
}

Shape::~Shape() {
}

double vectorMax(std::vector<double> vec) {
    double max = vec[0];
    for (int i = 0; i < vec.size(); i++)
        if (vec[i] > max)
            max = vec[i];
    return max;
}

double vectorMin(std::vector<double> vec) {
    double min = vec[0];
    for (int i = 0; i < vec.size(); i++)
        if (vec[i] < min)
            min = vec[i];
    return min;
}

void Shape::updatePoints() {
    this->points_transformed.resize(this->points.size());
    Mat3 affine = Mat3(std::cos(this->rotation), std::sin(this->rotation), 0, -std::sin(this->rotation), std::cos(this->rotation), 0, 0, 0, 1) * Mat3(this->scale.x, 0, 0, 0, this->scale.y, 0, 0, 0, 1); // * Mat3(1, 0, this->position.x, 0, 1, this->position.y, 0, 0, 1);
    for (int i = 0; i < this->points.size(); i++) {
        this->points_transformed[i] = affine * this->points[i];
        this->points_transformed[i] += position;
    }
}

void Shape::setTransform(Vec3 position, double rotation, Vec3 scale) {
    this->position = position;
    this->rotation = rotation;
    this->scale = scale;
    this->updatePoints();
}

bool isVisible(Vec3 point, std::vector<Shape> &shape, int pos) {
    for (int i = 0; i < pos; i++) {
        bool inside_shape = true;
        for (int j = 0; j < shape[i].points_transformed.size(); j++) {
            if (pointOrientation(shape[i].points_transformed[j], shape[i].points_transformed[(j + 1) % shape[i].points_transformed.size()], point) == 1) {
                inside_shape = false;
                break;
            }
        }
        if (inside_shape == shape[i].clippingType)
            return false;
    }
    return true;
}

void Shape::clipDrawLine(Engine *engine, Vec3 a, Vec3 b, std::vector<Shape> &shape, int pos, int &pattern) {
    bool a_visible = isVisible(a, shape, pos);
    bool b_visible = isVisible(b, shape, pos);

    if (!pos) {
        drawLine(engine, a, b, this->color, 0xFFFFFFFF);
        return;
    }

    Vec3 inter, a_sub, b_sub;
    bool first = true;
    for (int i = 0; i < pos; i++) {
        for (int j = 0; j < shape[i].points_transformed.size(); j++) {
            if (lineIntersection(a, b, shape[i].points_transformed[j], shape[i].points_transformed[(j + 1) % shape[i].points_transformed.size()], inter)) {
                if (first) {
                    a_sub = inter;
                    b_sub = inter;
                    first = false;
                }
                if (distance(a, inter) < distance(a, a_sub))
                    a_sub = inter;
                if (distance(b, inter) < distance(b, b_sub))
                    b_sub = inter;
            }
        }
    }

    if (a_visible && b_visible) {
        if (first) {
            drawLine(engine, a, b, this->color, 0xFFFFFFFF);
            return;
        }
        drawLine(engine, a, a_sub, this->color, 0xFFFFFFFF);
        drawLine(engine, a_sub, b_sub, this->color, 0xFF00FF00);
        drawLine(engine, b_sub, b, this->color, 0xFFFFFFFF);
    }

    if (!a_visible && !b_visible) {
        if (first) {
            drawLine(engine, a, b, this->color, 0xFF00FF00);
            return;
        }
        drawLine(engine, a, a_sub, this->color, 0xFF00FF00);
        drawLine(engine, a_sub, b_sub, this->color, 0xFFFFFFFF);
        drawLine(engine, b_sub, b, this->color, 0xFF00FF00);
    }

    if (a_visible && !b_visible) {
        drawLine(engine, a, a_sub, this->color, 0xFFFFFFFF);
        drawLine(engine, a_sub, b, this->color, 0xFF00FF00);
    }

    if (!a_visible && b_visible) {
        drawLine(engine, a, b_sub, this->color, 0xFF00FF00);
        drawLine(engine, b_sub, b, this->color, 0xFFFFFFFF);
    }
}

void Shape::draw(Engine *engine, std::vector<Shape> &shape, int pos) {
    int pattern = 0xFFFFFFFF;
    for (int i = 0; i < this->points_transformed.size(); i++)
        clipDrawLine(engine, this->points_transformed[i], this->points_transformed[(i + 1) % this->points_transformed.size()], shape, pos, pattern);
}
