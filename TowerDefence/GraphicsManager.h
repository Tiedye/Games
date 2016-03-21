#pragma once

#include <Windows.h>

const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;

class GraphicsManager
{
public:
	GraphicsManager();
	~GraphicsManager();

	bool Initialize(int screen_width, int screen_height, HWND window);
	void Shutdown();
	bool Frame();

private:
	bool Render();
};