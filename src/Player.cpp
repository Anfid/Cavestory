#include "../headers/Player.h"
#include "../headers/Graphics.h"

namespace player_const {
    const float RUN_SPEED = 0.2f;
}

Player::Player() {}

Player::Player(Graphics &graphics, float x, float y) :
        AnimatedSprite(graphics, "../content/sprites/MyChar.png", 0, 0, 16, 16, x, y, 100)
{
    graphics.loadImage("../content/sprites/MyChar.png");

    this->setupAnimations();
    this->playAnimation("IdleRight");
}

void Player::setupAnimations() {
    this->addAnimation(1, 0, 0, "IdleLeft", 16, 16, Vector2(0,0));
    this->addAnimation(1, 0, 16, "IdleRight", 16, 16, Vector2(0,0));
    this->addAnimation(3, 0, 0, "RunLeft", 16, 16, Vector2(0,0));
    this->addAnimation(3, 0, 16, "RunRight", 16, 16, Vector2(0,0));
}

void Player::animationDone(std::string currentAnimation) {

}

void Player::moveLeft() {
    this->_dx = -player_const::RUN_SPEED;
    this->playAnimation("RunLeft");
    this->_facing = LEFT;
}

void Player::moveRight() {
    this->_dx = player_const::RUN_SPEED;
    this->playAnimation("RunRight");
    this->_facing = RIGHT;
}

void Player::stopMoving() {
    this->_dx = 0;
    this->playAnimation(_facing == RIGHT ? "IdleRight" : "IdleLeft");
}

void Player::update(float elapsedTime) {
    // Move by _dx
    this->_x += this->_dx * elapsedTime;

    AnimatedSprite::update(elapsedTime);
}

void Player::draw(Graphics &graphics) {
    AnimatedSprite::draw(graphics, this->_x, this->_y);
}

