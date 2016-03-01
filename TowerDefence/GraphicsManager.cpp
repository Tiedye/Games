#include "GraphicsManager.h"

GraphicsManager::GraphicsManager() { }

GraphicsManager::~GraphicsManager() { }

bool GraphicsManager::Initialize(int screen_width, int screen_height, HWND window) { return true; }

void GraphicsManager::Shutdown() { }

bool GraphicsManager::Frame() { return true; }

bool GraphicsManager::Render() { return true; }