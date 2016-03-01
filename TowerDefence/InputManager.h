#pragma once

class InputManager
{
public:
	InputManager();
	~InputManager();

	void Initialize();

	void KeyUp(size_t);
	void KeyDown(size_t);

	bool IsKeyDown(size_t);

private:
	bool keys_[256] = { 0 };
};