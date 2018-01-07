#ifndef CAVESTORY_GRAPHICS_H
#define CAVESTORY_GRAPHICS_H

/* Graphics class
 * Holds all information dealing with graphics of the game
 */

#include <map>
#include <string>

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Surface;
struct SDL_Texture;
struct SDL_Rect;

class Graphics {
public:
    Graphics();
    ~Graphics();

    /* SDL_Surface* loadImage(...)
     * Loads an image into _spriteSheets map if it doesn't already exist.
     * As a result each image will only be loaded once.
     * Returns the image from the map whether it was just loaded or not.
     */
    SDL_Surface* loadImage(const std::string &filepath);

    /* void blitSurface(...)
     * Draws a texture to a certain part of the screen
     */
    void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);

    /* void flip(...)
     * Renders everything to the screen
     */
    void flip();

    /* void clear(...)
     * Clears the screen
     */
    void clear();

    SDL_Renderer* getRenderer() const;
    
private:
    SDL_Window* _window;
    SDL_Renderer* _renderer;

    std::map<std::string, SDL_Surface*> _spriteSheets;
};

#endif //CAVESTORY_GRAPHICS_H
