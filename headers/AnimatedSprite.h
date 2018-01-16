#ifndef CAVESTORY_ANIMATEDSPRITE_H
#define CAVESTORY_ANIMATEDSPRITE_H

#include <map>
#include <vector>

#include "Sprite.h"
#include "globals.h"

class Graphics;

/* AnimatedSprite class
 * Holds logic for animating sprites
 */

class AnimatedSprite : protected Sprite {
public:
    AnimatedSprite();
    AnimatedSprite(Graphics &graphics, const std::string &filepath, int sourceX, int sourceY,
                   int width, int height, float posX, float posY, float timeToUpdate);

    void playAnimation(std::string animation, bool once = false);
    void update(int elapsedTime);
    void draw(Graphics &graphics, int x, int y);

protected:
    double _timeToUpdate;
    bool _currentAnimationOnce;
    std::string _currentAnimation;

    /* void addAnimation(...)
     * Adds an animation to the map of animations for the sprite
     */
    void addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset);
    void resetAnimations();
    void stopAnimation();
    void setVisible(bool visible);

    /* void animationDone(...)
     * Logic that happens when the animation ends
     */
    virtual void animationDone(std::string currentAnimation) = 0;

    virtual void setupAnimations() = 0;

private:
    std::map<std::string, std::vector<SDL_Rect>> _animations;
    std::map<std::string, Vector2> _offsets;

    int _frameIndex;
    double _timeElapsed;
    bool _visible;
};

#endif //CAVESTORY_ANIMATEDSPRITE_H
