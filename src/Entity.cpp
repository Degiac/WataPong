#include "Entity.h"

#include <cstdio>

Entity::Entity(int type, bool collidable, int x, int y, int w, int h, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha)
{
    this->type = type;
    this->collidable = collidable;

    rect = { x, y, w, h };

    this->x = (float)x;
    this->y = (float)y;
    SpeedX = 0;
    SpeedY = 0;
    angle = 0;
    xDir = 1;
    yDir = 1;

    this->red = red;
    this->green = green;
    this->blue = blue;
    this->alpha = alpha;
}

void Entity::OnCollision()
{
    if(y < 200)
        yDir = DOWN;
    else
        yDir = UP;
}

void Entity::OnCollision(int ballOffset)
{
    /* Calculates new angle and direction */
    angle = (2*MAX_ANGLE * ballOffset) / (RACKET_HEIGHT+rect.h);

    if(angle < 0)
    {
        yDir = DOWN;
        angle = -angle;
    }
    else
        yDir = UP;

    if(x < 400)
        xDir = RIGHT;
    else
        xDir = LEFT;
}

void Entity::OnLoop()
{
    if(type == BALL)
    {
        /* Calculates the ball's horizontal and vertical speed */
        SpeedY = BALL_SPEED * yDir * sin(angle * M_PI/180) * Speed::SpeedControl.GetSpeedFactor();
        SpeedX = BALL_SPEED * xDir * cos(angle * M_PI/180) * Speed::SpeedControl.GetSpeedFactor();
    }
    else if(type == RACKET)
    {
        SpeedY = yDir * RACKET_SPEED * Speed::SpeedControl.GetSpeedFactor();
        yDir = 0;
        if(y + SpeedY > (480 - rect.h) || y + SpeedY < 20) SpeedY = SpeedX = 0;
    }

}

void Entity::OnMove()
{
    if(type == FIELD) return;

    x += SpeedX;
    y += SpeedY;

    rect.x = (int)x;
    rect.y = (int)y;
}
