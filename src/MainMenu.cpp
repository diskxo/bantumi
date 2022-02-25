#include "Platform/Platform.hpp"
#include <mainMenu/MainMenu.hpp>

using namespace sf;
MainMenu::MainMenu(float width, float height)
{
	// load font
	sf::Font font;
	font.loadFromFile("./src/assets/fonts/Roboto-Black.ttf");

	// 2vs
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(Color::Blue);
	mainMenu[0].setString("1 VS 1");
	mainMenu[0].setCharacterSize(40);
	mainMenu[0].setPosition(500, 100);

	// CPUvs
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(Color::Blue);
	mainMenu[0].setString("1 VS CPU");
	mainMenu[0].setCharacterSize(40);
	mainMenu[0].setPosition(500, 100);

	// quit
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(Color::Blue);
	mainMenu[0].setString("Exit");
	mainMenu[0].setCharacterSize(40);
	mainMenu[0].setPosition(500, 100);

	mainMenuSelected = 0;
}

MainMenu::~MainMenu()
{
}

// draw MainMenu
void MainMenu::Draw(RenderWindow& window)
{
	for (int i = 0; i < 3; i++)
	{
		window.draw(mainMenu[i]);
	}
}

// move up
void MainMenu::moveUp()
{
	if (mainMenuSelected - 1 >= -1)
	{
		mainMenu[mainMenuSelected].setFillColor(Color::White);

		mainMenuSelected--;
		if (mainMenuSelected == -1)
		{
			mainMenuSelected = 2;
		}
		mainMenu[mainMenuSelected].setFillColor(Color::Blue);
	}
}

// move down
void MainMenu::moveDown()
{
	if (mainMenuSelected + 1 <= maxMainMenu)
	{
		mainMenu[mainMenuSelected].setFillColor(Color::White);

		mainMenuSelected++;
		if (mainMenuSelected == 3)
		{
			mainMenuSelected = 0;
		}
		mainMenu[mainMenuSelected].setFillColor(Color::Blue);
	}
}