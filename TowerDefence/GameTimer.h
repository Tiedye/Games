#pragma once

#include <Windows.h>

class GameTimer
{
public:
	GameTimer();
	~GameTimer();

	void Tick();
	void Reset();
	float Delta();
	void Pause();
	void UnPause();

private:

	bool paused_;
	LARGE_INTEGER last_;
	LARGE_INTEGER pause_;
	LARGE_INTEGER delta_;
	float deltaf_;
	LARGE_INTEGER freq_;

};

