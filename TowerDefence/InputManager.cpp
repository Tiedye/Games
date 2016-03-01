#include "InputManager.h"

InputManager::InputManager() {}

InputManager::~InputManager() {}

void InputManager::Initialize() {}

void InputManager::KeyDown(size_t key) {
	if (key > 256) return;
	keys_[key] = true;
}

void InputManager::KeyUp(size_t key) {
	if (key > 256) false;
	keys_[key] = false;
}

bool InputManager::IsKeyDown(size_t key) {
	return keys_[key];
}