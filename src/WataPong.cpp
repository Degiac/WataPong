#include "WataPong.h"

WataPong::WataPong()
{
    wataWindow = NULL;
    wataRenderer = NULL;
    Running = true;
}

int WataPong::OnExecute()
{
    if(!OnInit())
        return -1;

    while(Running)
    {
        Speed::SpeedControl.OnLoop();
        Running = wataWorld.OnLoop();
        SDL_Delay(20);
    }

    return 0;
}

bool WataPong::OnInit()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
        return false;
    if((wataWindow = SDL_CreateWindow("WataPong", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 500, SDL_WINDOW_SHOWN)) == NULL)
        return false;
    if((wataRenderer = SDL_CreateRenderer(wataWindow, -1, SDL_RENDERER_ACCELERATED)) == NULL)
        return false;

    wataWorld.addEntity(new Entity(RACKET, 1, 50, 200, 30, RACKET_HEIGHT, 0x5F, 0x5F, 0x5F, 0xFF));
    wataWorld.addEntity(new Entity(RACKET, 1, 730, 200, 30, RACKET_HEIGHT, 0x5F, 0x5F, 0x5F, 0xFF));

    wataWorld.addEntity(new Entity(FIELD, 0, 395, 0, 10, 500, 0xBA, 0xBA, 0xBA, 0xFF));
    wataWorld.addEntity(new Entity(FIELD, 0, 350, 200, 100, 100, 0xBA, 0xBA, 0xBA, 0xFF));
    wataWorld.addEntity(new Entity(FIELD, 0, 360, 210, 80, 80, 0xFF, 0xFF, 0xFF, 0xFF));
    wataWorld.addEntity(new Entity(FIELD, 0, 390, 240, 20, 20, 0xBA, 0xBA, 0xBA, 0xFF));

    wataWorld.addEntity(new Entity(BALL, 1, 385, 235, 30, 30, 0x2B, 0x57, 0x9A, 0xFF));

    std::thread (&WataPong::OnRender, this).detach();

    return true;
}

void WataPong::OnRender()
{
    while(Running)
    {
        SDL_SetRenderDrawColor(wataRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(wataRenderer);

        std::vector<Entity> *entityList = wataWorld.getEntityList();

        for(int i = 0; i < (int)entityList->size(); ++i)
        {
            SDL_SetRenderDrawColor(wataRenderer,
                                   entityList->at(i).getRed(),
                                   entityList->at(i).getGreen(),
                                   entityList->at(i).getBlue(),
                                   entityList->at(i).getAlpha());

            SDL_RenderFillRect(wataRenderer, entityList->at(i).getRect());
        }

        SDL_RenderPresent(wataRenderer);
    }
}

void WataPong::OnCleanUp()
{

}

int main(int argc, char *argv[])
{
    WataPong game;

    return game.OnExecute();
}
