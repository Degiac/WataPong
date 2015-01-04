#ifndef FPS_H
#define FPS_H

#include <SDL.h>

class FPS
{
    public:
        FPS();
        virtual ~FPS();

        void OnLoop();
        int getFPS();
        double getSpeedFactor();

        static FPS FPSControl;

    protected:
    private:
        int OldTime;
        int LastTime;

        double SpeedFactor;

        int NumFrames;
        int Frames;
};

#endif // FPS_H
