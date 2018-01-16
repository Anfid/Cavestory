#ifndef CAVESTORY_GAME_H
#define CAVESTORY_GAME_H

#include "../headers/Player.h"

class Graphics;

class Game {
public:
    Game();
    ~Game();
private:
    void gameLoop();
    void draw(Graphics &graphics);
    void update(float elapsedTime);

    Player _player;
};

#endif //CAVESTORY_GAME_H
