#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <SDL2/SDL.h>

#include "utils.hpp"

class Engine {
    private:
        int width, height;
        std::string window_title;

        SDL_Window * window;
        SDL_Renderer * renderer;
        SDL_Texture * texture;
        SDL_Surface * surface;
    public:
        Engine(std::string, int, int);
        ~Engine();
};

#endif
