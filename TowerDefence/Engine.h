#pragma once

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>

#include "InputManager.h"
#include "GraphicsManager.h"

class Engine
{
public:
	Engine();
	~Engine();

	bool Initialize();
	void Shutdown();
	void Run();

	LRESULT CALLBACK MessageHandler(HWND window, UINT msg, WPARAM wparam, LPARAM lparam);

private:
	bool Frame();
	void InitializeWindows(int &screen_width, int &screen_height);
	void ShutdownWindows();

	LPCWSTR application_name_;
	HINSTANCE instance_;
	HWND window_;

	InputManager input_manager_;
	GraphicsManager graphics_manager_;	
};