#include "GameWorld.h"

#include <cstdio>

GameWorld::GameWorld()
{
    ballIdx = racket1Idx = racket2Idx = -1;
    paused = true;
}

bool GameWorld::OnLoop()
{
    OnEvent();

    if(paused) return true;

    for(auto i = EntityList.begin(); i != EntityList.end(); ++i)
        i->OnLoop();

    // CollisionChecker();

    for(auto i = EntityList.begin(); i != EntityList.end(); ++i)
        i->OnMove();

    return true;
}

void GameWorld::addEntity(Entity *newEntity)
{
    EntityList.push_back(*newEntity);

    if(newEntity->getType() == BALL) ballIdx = (int)EntityList.size() - 1;
    if(newEntity->getType() == RACKET)
    {
        if(racket1Idx < 0) racket1Idx = (int)EntityList.size() - 1;
        else racket2Idx = (int)EntityList.size() - 1;
    }
}

void GameWorld::OnEvent()
{
    SDL_PollEvent(&event);

    if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_p) paused = !paused;
    else
    {
        const Uint8* keystate = SDL_GetKeyboardState(NULL);

        if(keystate[SDL_SCANCODE_W]) EntityList[racket1Idx].setUpOrDown(UP);
        if(keystate[SDL_SCANCODE_S]) EntityList[racket1Idx].setUpOrDown(DOWN);
        if(keystate[SDL_SCANCODE_DOWN]) EntityList[racket2Idx].setUpOrDown(DOWN);
        if(keystate[SDL_SCANCODE_UP]) EntityList[racket2Idx].setUpOrDown(UP);
    }
}
