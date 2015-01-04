#ifndef SPEED_H
#define SPEED_H

#include <SDL.h>

class Speed
{
    public:
        Speed();

        void OnLoop();
        double GetSpeedFactor();

        static Speed SpeedControl;

    protected:
    private:
        int OldTime;
        int LastTime;

        double SpeedFactor;
};

#endif
