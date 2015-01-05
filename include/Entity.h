#ifndef ENTITY_H
#define ENTITY_H

#define _USE_MATH_DEFINES

#include <SDL.h>
#include <cmath>
#include "Speed.h"

const int MAX_ANGLE = 70;
const int RACKET_HEIGHT = 100;
const int BALL_SPEED = 50;
const int RACKET_SPEED = 40;
const int UP = -1;
const int DOWN = 1;
const int LEFT = -1;
const int RIGHT = 1;

enum
{
    BALL,
    RACKET,
    FIELD
};

class Entity
{
    public:
        Entity(int type, bool collidable, int x, int y, int w, int h, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha);

        void OnCollision();
        void OnCollision(int h);
        void OnLoop();
        void OnMove();

        int getType() { return type; }
        void setXDir(int dir) { xDir = dir; }
        void setYDir(int dir) { yDir = dir; }
        bool isCollidable() { return collidable; }

        Uint8 getRed() { return red; }
        Uint8 getGreen() { return green; }
        Uint8 getBlue() { return blue; }
        Uint8 getAlpha() { return alpha; }
        void setRed(Uint8 red) { this->red = red; }
        void setGreen(Uint8 green) { this->green = green; }
        void setBlue(Uint8 blue) { this->blue = blue; }
        void setAlpha(Uint8 alpha) { this->alpha = alpha; }

        SDL_Rect* getRect() { return &rect; }
        void setRect(SDL_Rect rect) { this->rect = rect; }
        int getMidPoint() { return (rect.y + rect.h/2); }
        float getX() { return x; }
        float getY() { return y; }
        void setX(float x) { this->x = x; }
        void setY(float y) { this->y = y; }
    protected:
    private:
        bool collidable;

        int type;
        int angle;
        int yDir;
        int xDir;

        float x;
        float y;
        float SpeedX;
        float SpeedY;

        Uint8 red;
        Uint8 green;
        Uint8 blue;
        Uint8 alpha;
        SDL_Rect rect;
};

#endif // ENTITY_H
