// License: CC BY-NC-SA 4.0
/*
 * main.cpp
 *
 * Lab 3.
 *
 * Written by AlexeyFilich
 * 10 mar 2021
 */

#include <cmath>
#include <iostream>
#include <vector>

#include "Color.hpp"
#include "Engine.hpp"
// #include "MakeString.hpp"
#include "Mat3.hpp"
#include "primitives.hpp"
#include "Shape.hpp"
#include "utils.hpp"
#include "Vec3.hpp"

#define WIDTH 1280
#define HEIGHT 720

int main(int argc, char* args[]) {
    Engine engine("Template", WIDTH, HEIGHT, Color(0x0));
    int x, y;
    int selected = 0;

    std::vector<Shape> shapes;
    // Rect
    shapes.push_back(Shape({
        Vec3(-1.0f, -0.5f, 0.0f),
        Vec3( 1.0f, -0.5f, 0.0f),
        Vec3( 1.0f,  0.5f, 0.0f),
        Vec3(-1.0f,  0.5f, 0.0f),
    }, Color(255, 0, 0), CLIP_OUTER, Vec3(WIDTH / 2, HEIGHT / 2, 0.0f), 0.0f, Vec3(500.0f, 500.0f, 0.0f)));

    // Oval
    shapes.push_back(Shape({}, Color(0, 0, 255), CLIP_INNER, Vec3(WIDTH / 2, HEIGHT / 2, 0.0f), 0.0f, Vec3(100.0f, 100.0f, 0.0f)));
    for (double t = 0; t < 2.0f * M_PI; t += 0.1f)
        shapes[shapes.size() - 1].points.push_back(Vec3(2.0f * std::cos(t), std::sin(t), 0.0f));
    shapes[shapes.size() - 1].updatePoints();

    // Trap
    shapes.push_back(Shape({
        Vec3( 0.0f, -0.5f, 0.0f),
        Vec3( 0.5f, -0.5f, 0.0f),
        Vec3( 0.5f,  0.5f, 0.0f),
        Vec3(-0.5f,  0.5f, 0.0f),
    }, Color(0, 255, 0), CLIP_INNER, Vec3(WIDTH / 2, HEIGHT / 2, 0.0f), 0.0f, Vec3(300.0f, 300.0f, 0.0f)));

    // Engine loop
    while (!engine.shouldExit()) {
        SDL_Event event;
        while (engine.pollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.scancode) {
                    case SDL_SCANCODE_ESCAPE: engine.shutdown(); break;
                    case SDL_SCANCODE_SPACE: selected = (selected + 1) % shapes.size(); break;
                    default: log("Event", "SDL_KEYDOWN event processed"); break;
                }
            }
        }

        engine.clear();

        SDL_GetMouseState(&x, &y);
        shapes[selected].setTransform(Vec3(x, y, 0.0f), shapes[selected].rotation, shapes[selected].scale);

        for (int i = 0; i < shapes.size(); i++)
            shapes[i].draw(&engine, shapes, i);

        engine.draw();
        SDL_Delay(16);
    }
    return 0;
}
