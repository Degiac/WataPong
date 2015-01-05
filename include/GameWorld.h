#ifndef GAMEWORLD_H
#define GAMEWORLD_H

#include "Entity.h"
#include <vector>

class GameWorld
{
    public:
        GameWorld();

        bool OnLoop();
        void addEntity(Entity *newEntity);
        std::vector<Entity>* getEntityList() { return &EntityList; }
    protected:
    private:
        void CollisionChecker();
        bool OnEvent();

        bool paused;
        int ballIdx;
        int racket1Idx;
        int racket2Idx;
        SDL_Event event;
        std::vector<Entity> EntityList;
};

#endif // GAMEWORLD_H
