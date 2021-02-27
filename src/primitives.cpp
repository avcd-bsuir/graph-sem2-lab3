#include "primitives.hpp"

void drawLine(Engine * engine, double x1, double y1, double x2, double y2, Color c1, Color c2) {
    double dots = std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
    for (double u = 0.0f; u < 1.0f; u += 1 / dots)
        engine->setPixel(lerp(x1, x2, u), lerp(y1, y2, u), lerp(c1, c2, u));
}

void drawLine(Engine * engine, double x1, double y1, double x2, double y2, Color c) {
    drawLine(engine, x1, y1, x2, y2, c, c);
}
