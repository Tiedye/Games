
#include "Engine.h"

int WINAPI WinMain(HINSTANCE instance, HINSTANCE prev_instance, PSTR cmd_line, int cmd_show) {
	Engine engine;

	if (engine.Initialize()) {
		engine.Run();
	}

	engine.Shutdown();

	return 0;
}