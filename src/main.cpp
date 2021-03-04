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

    std::vector<Vec3> pts;

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

        // bool clr = false;
        // for (int x = 0; x < WIDTH; x++) {
        //     for (int y = 0; y < HEIGHT; y++) {
        //         if (clr) {
        //             clr = !clr;
        //             engine.setPixel(x, y, Color(0, 0, 0));
        //         } else {
        //             clr = !clr;
        //             engine.setPixel(x, y, Color(255, 255, 255));
        //         }
        //     }
        //     clr = !clr;
        // }

        engine.draw();
        SDL_Delay(16);
    }
    return 0;
}
