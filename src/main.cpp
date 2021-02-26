// License: CC BY-NC-SA 4.0
/*
 * main.cpp
 *
 * This file should be used as a template file.
 *
 * Written by AlexeyFilich
 * 25 feb 2020
 */

#include <iostream>

#include "Engine.hpp"
#include "MakeString.hpp"

#define WIDTH 1280
#define HEIGHT 720

// class Vec3 {
//     private:
//         double data[3];
//     public:
//         Vec3();
//         ~Vec3();
// };
//
// class Mat3 {
//     private:
//         Vec3 data[3];
//     public:
//         Mat3();
//         ~Mat3();
// };

// https://github.com/adafruit/micropython-adafruit-framebuf/blob/master/framebuf.py

template<typename T>
T lerp(T a, T b, float u) {
    return (1.0f - u) * a + u * b;
}

void drawLine(Engine * engine, float x1, float y1, float x2, float y2, Color c1, Color c2) {
    float dots = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    for (float u = 0.0f; u < 1.0f; u += 1 / dots)
        engine->setPixel(lerp(x1, x2, u), lerp(y1, y2, u), lerp(c1, c2, u));
}

void drawLine(Engine * engine, float x1, float y1, float x2, float y2, Color c) {
    drawLine(engine, x1, y1, x2, y2, c, c);
}

int main(int argc, char* args[]) {
    Engine engine("Template", WIDTH, HEIGHT, Color(0, 0, 0));

    int x1, x2, y1, y2;

    while (!engine.shouldExit()) {
        SDL_Event event;
        while (engine.pollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.scancode) {
                    case SDL_SCANCODE_ESCAPE: engine.shutdown(); break;
                    default: log("Event", "SDL_KEYDOWN event processed"); break;
                }
            }
        }

        engine.clear();

        // Draw loop code here
        for (int i = 0; i < 100; i++) {
            x1 = rand() % WIDTH;
            x2 = rand() % WIDTH;
            y1 = rand() % HEIGHT;
            y2 = rand() % HEIGHT;
            drawLine(&engine, x1, y1, x2, y2, Color(0, 255, 0), Color(255, 255, 0));
        }

        engine.draw();
    }
    return 0;
}
