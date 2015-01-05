#ifndef WATAPONG_H
#define WATAPONG_H

#include "GameWorld.h"
#include "Entity.h"
#include <SDL.h>
#include <vector>

class WataPong
{
    public:
        WataPong();
        int OnExecute();
        bool OnInit();
        void OnRender();
        void OnCleanUp();
    protected:
    private:
        bool Running;
        SDL_Window *wataWindow;
        SDL_Renderer *wataRenderer;
        GameWorld wataWorld;
};

#endif // WATAPONG_H
