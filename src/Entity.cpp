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

    this->red = red;
    this->green = green;
    this->blue = blue;
    this->alpha = alpha;
}

void Entity::OnCollision()
{
    angle = (360 - angle%360);
}

void Entity::OnCollision(int ballOffset)
{
    /* If the ball hits the top or the bottom side of a racket **
    ** it should behave like when it hits the field sides      */
    if(ballOffset < 0 || ballOffset > RACKET_HEIGHT)
    {
        OnCollision();
        return;
    }

    /* transforms ballOffset in a value between MAX_ANGLE **
    **  and -MAX_ANGLE proportional to its value          */
    ballOffset = (-2 * ballOffset * MAX_ANGLE) / RACKET_HEIGHT + MAX_ANGLE;

    /* calculates the new angle */
    if(x < 400)
    {
        angle = (ballOffset + 360) % 360;
    }
    else
    {
        angle = 180 - ballOffset;
    }
}

void Entity::OnLoop()
{
    if(type == BALL)
    {
        /* Calculates the ball's horizontal and vertical speed */
        SpeedY = BALL_SPEED * -cos((angle-90) * M_PI/180) * Speed::SpeedControl.GetSpeedFactor();
        SpeedX = BALL_SPEED * -sin((angle-90) * M_PI/180) * Speed::SpeedControl.GetSpeedFactor();
    }
    else if(type == RACKET)
    {
        SpeedY = upOrDown * RACKET_SPEED * Speed::SpeedControl.GetSpeedFactor();
        upOrDown = 0;
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
