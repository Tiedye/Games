#include "Engine.h"

static LRESULT CALLBACK wnd_proc(HWND window, UINT, WPARAM, LPARAM);

static Engine* application_handle;

Engine::Engine()
{
}

Engine::~Engine()
{
}

bool Engine::Initialize()
{
	int screen_width = 0;
	int screen_height = 0;

	InitializeWindows(screen_width, screen_height);

	input_manager_.Initialize();

	return graphics_manager_.Initialize(screen_width, screen_height, window_);
}

void Engine::Shutdown()
{
	graphics_manager_.Shutdown();

	ShutdownWindows();
}

void Engine::Run()
{
	MSG msg;
	bool running = true;

	ZeroMemory(&msg, sizeof(msg));

	while (running) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		switch (msg.message)
		{
		case WM_QUIT:
			running = false;
			break;
		default:
			if (!Frame()) running = false;
		}
	}
}

bool Engine::Frame()
{
	if (input_manager_.IsKeyDown(VK_ESCAPE)) {
		return false;
	}

	return graphics_manager_.Frame();
}

LRESULT CALLBACK Engine::MessageHandler(HWND window, UINT msg, WPARAM wparam, LPARAM lparam) {
	switch (msg)
	{
	case WM_KEYDOWN:
		input_manager_.KeyDown((size_t)wparam);
		return 0;
	case WM_KEYUP:
		input_manager_.KeyUp((size_t)lparam);
		return 0;
	default:
		return DefWindowProc(window, msg, wparam, lparam);
	}
}

void Engine::InitializeWindows(int & screen_width, int & screen_height)
{
	WNDCLASSEX wc;
	DEVMODE screen_settings;
	int pos_x;
	int pos_y;

	application_handle = this;

	instance_ = GetModuleHandle(NULL);

	application_name_ = L"App";

	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	wc.lpfnWndProc = wnd_proc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = instance_;
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hIconSm = wc.hIcon;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = application_name_;
	wc.cbSize = sizeof(WNDCLASSEX);

	RegisterClassEx(&wc);

	screen_width = GetSystemMetrics(SM_CXSCREEN);
	screen_height = GetSystemMetrics(SM_CYSCREEN);

	if (FULL_SCREEN) {
		//memset(&screen_settings, 0, sizeof(screen_settings));
		screen_settings.dmSize = sizeof(screen_settings);
		screen_settings.dmPelsWidth = (DWORD)screen_width;
		screen_settings.dmPelsHeight = (DWORD)screen_height;
		screen_settings.dmBitsPerPel = 32;
		screen_settings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;

		ChangeDisplaySettings(&screen_settings, CDS_FULLSCREEN);

		pos_x = pos_y = 0;
	}
	else
	{
		screen_width = 800; // TODO make this not hard coded (preferences eventually)
		screen_height = 600;

		pos_x = (GetSystemMetrics(SM_CXSCREEN) - screen_width) / 2;
		pos_y = (GetSystemMetrics(SM_CYSCREEN) - screen_height) / 2;
	}

	window_ = CreateWindowEx(WS_EX_APPWINDOW, application_name_, application_name_,
		WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_POPUP, pos_x, pos_y, screen_width, screen_height,
		NULL, NULL, instance_, NULL);

	ShowWindow(window_, SW_SHOW);
	SetForegroundWindow(window_);
	SetFocus(window_);

	ShowCursor(false);

}

void Engine::ShutdownWindows() {
	ShowCursor(true);

	if (FULL_SCREEN) {
		ChangeDisplaySettings(NULL, 0);
	}

	DestroyWindow(window_);

	UnregisterClass(application_name_, instance_);
}

LRESULT CALLBACK wnd_proc(HWND window, UINT msg, WPARAM wparam, LPARAM lparam) {
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_CLOSE:
		PostQuitMessage(0);
		return 0;
	default:
		return application_handle->MessageHandler(window, msg, wparam, lparam);
	}
}