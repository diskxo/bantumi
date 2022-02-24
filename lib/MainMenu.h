#pragma once
#include "Platform/Platform.hpp"
#define maxMainMenu 3

class MainMenu
{
	MainMenu(float width, float height);

	void Draw();
	void MoveUp();
	void MoveDown();
}