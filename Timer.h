#ifndef TIMER_H_
#define TIMER_H_
#include"SDL_ttf.h"
#include"string"
class LTimer
{
    public:
		LTimer();
		void start();
		void stop();
		void pause();
		void unpause();
		Uint32 getTicks();
		bool isStarted();
		bool isPaused();
		int deltaTime();

    private:
		Uint32 mStartTicks;
		Uint32 mPausedTicks;
		bool mPaused;
		bool mStarted;
};

#endif // TIMER_H_
