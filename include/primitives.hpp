#ifndef PRIMITIVES_HPP
#define PRIMITIVES_HPP

#include "Color.hpp"
#include "Engine.hpp"

// This function really shouldn't be here, but C++ standart no longer supports "export" keyword, that was supposed to export instantiable.
template<typename T>
T lerp(T a, T b, float u);

void drawLine(Engine * engine, double x1, double y1, double x2, double y2, Color c1, Color c2);

void drawLine(Engine * engine, double x1, double y1, double x2, double y2, Color c);

#endif
