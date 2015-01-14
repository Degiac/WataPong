#include "../include/Speed.h"

Speed Speed::SpeedControl;

Speed::Speed()
{
    OldTime = 0;
    LastTime = 0;

    SpeedFactor = 0;
}

void Speed::OnLoop()
{
    if(OldTime + 60 < (int)SDL_GetTicks()) {
        OldTime = SDL_GetTicks();
    }

    SpeedFactor = (SDL_GetTicks() - LastTime) / 60.0f;

    LastTime = SDL_GetTicks();
}

double Speed::GetSpeedFactor()
{
    return SpeedFactor;
}
