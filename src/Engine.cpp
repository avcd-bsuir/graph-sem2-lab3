#include "Engine.hpp"

Engine::Engine(std::string window_title, int width, int height) : window_title(window_title), width(width), height(height), window(nullptr), renderer(nullptr), texture(nullptr), surface(nullptr) {
}

Engine::~Engine() {
}
