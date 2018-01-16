#include <SDL2/SDL.h>

#include "../headers/Game.h"
#include "../headers/Input.h"
#include "../headers/Graphics.h"

namespace {
    const int FPS = 50;
    const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}

Game::Game() {
    SDL_Init(SDL_INIT_EVERYTHING);
    this->gameLoop();
}

Game::~Game() {

}

void Game::gameLoop() {
    Graphics graphics;
    Input input;
    SDL_Event event;

    this->_player = Player(graphics, 100, 100);

    int LAST_UPDATE_TIME = SDL_GetTicks();
    while (true) {
        input.beginNewFrame();

        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                if (event.key.repeat == 0) {
                    input.keyDownEvent(event);
                }
            } else if (event.type == SDL_KEYUP) {
                input.keyUpEvent(event);
            } else if (event.type == SDL_QUIT) {
                return;
            }
        }

        if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE)) {
            return;
        }

        if (input.isKeyHeld(SDL_SCANCODE_LEFT)) {
            this->_player.moveLeft();
        } else if (input.isKeyHeld(SDL_SCANCODE_RIGHT)) {
            this->_player.moveRight();
        } else {
            this->_player.stopMoving();
        }


        const int CURRENT_TIME_MS = SDL_GetTicks();
        int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
        this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
        LAST_UPDATE_TIME = CURRENT_TIME_MS;

        this->draw(graphics);
    }
}

void Game::draw(Graphics &graphics) {
    graphics.clear();

    _player.draw(graphics);

    graphics.flip();
}

void Game::update(float elapsedTime) {
    _player.update(elapsedTime);
}
