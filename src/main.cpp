// License: CC BY-NC-SA 4.0
/*
 * main.cpp
 *
 * This file should be used as a template file.
 *
 * Written by AlexeyFilich
 * 25 feb 2020
 */

#include <cmath>
#include <iostream>
#include <vector>

#include "Color.hpp"
#include "Engine.hpp"
// #include "MakeString.hpp"
#include "Mat3.hpp"
#include "primitives.hpp"
#include "utils.hpp"
#include "Vec3.hpp"

#define WIDTH 1280
#define HEIGHT 720

int main(int argc, char* args[]) {
    Engine engine("Template", WIDTH, HEIGHT, Color(0x0));

    std::vector<Vec3> pts = {
        Vec3(10, 10, 0),
        Vec3(110, 10, 0),
        Vec3(160, 110, 0),
        Vec3(60, 110, 0),
        Vec3(10, 10, 0),
    };

    Mat3 scale(3.0f, 3.0f, 3.0f);

    Vec3 u(WIDTH, -HEIGHT, 0);
    u = u.normalized();

    for (int i = 0; i < pts.size(); i++)
        pts[i] = scale * pts[i];

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

        for (int i = 0; i < pts.size() - 1; i++)
            drawLine(&engine, pts[i].x, pts[i].y, pts[i + 1].x, pts[i + 1].y, Color(255, 255, 255));

        // drawLine(&engine, Vec3(0, HEIGHT, 0), Vec3(0, HEIGHT, 0) + u, Color(0xFFFFFF));

        engine.draw();
        SDL_Delay(16);
    }
    return 0;
}
