#include <SDL2/SDL.h>
#include <SDL_image.h>

#include "../headers/Graphics.h"
#include "../headers/globals.h"

Graphics::Graphics() {
    SDL_CreateWindowAndRenderer(globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT, 0, &this->_window, &this->_renderer);
    SDL_SetWindowTitle(this->_window, "Cavestory");
}

Graphics::~Graphics() {
    SDL_DestroyWindow(this->_window);
}

SDL_Surface* Graphics::loadImage(const std::string &filepath) {
    if (this->_spriteSheets.count(filepath) == 0) {
        this->_spriteSheets[filepath] = IMG_Load(filepath.c_str());
    }
    return this->_spriteSheets[filepath];
}

void Graphics::blitSurface(SDL_Texture *source, SDL_Rect *sourceRectangle, SDL_Rect *destinationRectangle) {
    SDL_RenderCopy(this->_renderer, source, sourceRectangle, destinationRectangle);
}

void Graphics::flip() {
    SDL_RenderPresent(this->_renderer);
}

void Graphics::clear() {
    SDL_RenderClear(this->_renderer);
}

SDL_Renderer* Graphics::getRenderer() const {
    return this->_renderer;
}
