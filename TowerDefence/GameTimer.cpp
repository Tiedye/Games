#include "GameTimer.h"


GameTimer::GameTimer()
{
	QueryPerformanceFrequency(&freq_);
	Reset();
}


GameTimer::~GameTimer()
{
}

void GameTimer::Reset() {
	QueryPerformanceCounter(&last_);
	QueryPerformanceCounter(&pause_);
	delta_.QuadPart = 0;
	paused_ = true;
}

void GameTimer::Pause() {
	if (paused_) return;
	QueryPerformanceCounter(&pause_);
	paused_ = true;
}

void GameTimer::UnPause() {
	if (!paused_) return;
	LARGE_INTEGER pause_time;
	QueryPerformanceCounter(&pause_time);
	pause_time.QuadPart -= pause_.QuadPart;
	last_.QuadPart += pause_time.QuadPart;
	paused_ = false;
}

void GameTimer::Tick() {
	QueryPerformanceCounter(&delta_);
	delta_.QuadPart -= last_.QuadPart;
	last_.QuadPart += delta_.QuadPart;
	deltaf_ = static_cast<float>(delta_.QuadPart) / static_cast<float>(freq_.QuadPart);
}

float GameTimer::Delta() {
	return deltaf_;
}