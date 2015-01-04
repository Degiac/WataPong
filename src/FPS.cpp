#include "FPS.h"

FPS FPS::FPSControl;

FPS::FPS()
{
    OldTime = 0;
    LastTime = 0;

    SpeedFactor = 0;

    NumFrames = 0;
    Frames = 0;
}

FPS::~FPS()
{
    //dtor
}

void FPS::OnLoop()
{
    if(OldTime + 60 < SDL_GetTicks()) {
        OldTime = SDL_GetTicks();

        NumFrames = Frames;

        Frames = 0;
    }

    SpeedFactor = (SDL_GetTicks() - LastTime) / 60.0f;

    LastTime = SDL_GetTicks();

    Frames++;
}

int FPS::getFPS()
{
    return NumFrames;
}

double FPS::getSpeedFactor()
{
    return SpeedFactor;
}
