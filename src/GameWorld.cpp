#include "GameWorld.h"

GameWorld::GameWorld()
{

}

bool GameWorld::OnLoop()
{

    return true;
}

void GameWorld::addEntity(Entity *newEntity)
{
    EntityList.push_back(*newEntity);
}
