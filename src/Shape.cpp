#include "Shape.hpp"

Shape::Shape(bool closed) : closed(closed) {
}

Shape::Shape(std::vector<Vec3> points, bool closed) : points(points), closed(closed) {
}

Shape::Shape(std::vector<Vec3> points, std::vector<Color> colors, bool closed) : points(points), colors(colors), closed(closed) {
}

Shape::~Shape() {
}

void Shape::draw(Engine * engine) {
    for (int i = 0; i < this->points.size() - 1; i++)
        drawLine(engine, this->points[i], this->points[i + 1], (i < this->colors.size()) ? this->colors[i] : Color(255, 255, 255), (i + 1 < this->colors.size()) ? this->colors[i + 1] : Color(255, 255, 255), 0xFFFFFFFF);
    if (this->closed)
        drawLine(engine, this->points[0], this->points[this->points.size() - 1], (0 < this->colors.size()) ? this->colors[0] : Color(255, 255, 255), (this->points.size() - 1 < this->colors.size()) ? this->colors[this->points.size() - 1] : Color(255, 255, 255), 0xFFFFFFFF);
}

void Shape::draw(Engine * engine, Color color) {
    for (int i = 0; i < this->points.size() - 1; i++)
        drawLine(engine, this->points[i], this->points[i + 1], color, 0xFFFFFFFF);
    if (this->closed)
        drawLine(engine, this->points[0], this->points[this->points.size() - 1], color, 0xFFFFFFFF);
}
