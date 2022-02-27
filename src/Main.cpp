#include "Platform/Platform.hpp"
#include <vsPlayer/Game.h>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace util;
using namespace std;
using namespace sf;

int main()
{

	// create windows
	RenderWindow MainMenu(VideoMode(1024, 720), "Bantumi", Style::Close);

	sf::Font font;
	sf::Text mainMenu[3];
	// load font

	font.loadFromFile("./src/assets/fonts/Roboto-Black.ttf");

	int mainMenuSelected = 0;
	// 1vs1
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(Color::White);
	mainMenu[0].setString("1 VS 1");
	mainMenu[0].setCharacterSize(40);
	mainMenu[0].setPosition(500, 100);

	// CPUvs
	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(Color::Blue);
	mainMenu[1].setString("1 VS CPU");
	mainMenu[1].setCharacterSize(40);
	mainMenu[1].setPosition(500, 300);

	// quit
	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(Color::Blue);
	mainMenu[2].setString("Exit");
	mainMenu[2].setCharacterSize(40);
	mainMenu[2].setPosition(500, 500);

	while (MainMenu.isOpen())
	{
		Event event;

		MainMenu.clear();
		MainMenu.draw(mainMenu[0]);
		MainMenu.draw(mainMenu[1]);
		MainMenu.draw(mainMenu[2]);
		MainMenu.display();

		while (MainMenu.waitEvent(event))
		{
			if (event.type == Event::Closed)
			{
				MainMenu.close();
			}

			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::Up)
				{
					if (mainMenuSelected > 0)
					{
						mainMenu[mainMenuSelected].setFillColor(Color::Blue);
						MainMenu.clear();
						mainMenuSelected--;
						mainMenu[mainMenuSelected].setFillColor(Color::White);
					}
					break;
				}
				if (event.key.code == Keyboard::Down)
				{
					if (mainMenuSelected < 2)
					{
						mainMenu[mainMenuSelected].setFillColor(Color::Blue);
						MainMenu.clear();
						mainMenuSelected++;

						mainMenu[mainMenuSelected].setFillColor(Color::White);
					}
					break;
				}
				if (event.key.code == Keyboard::Return)
				{
					int x = mainMenuSelected;

					switch (x)
					{
						case 0:
							cout << "v1 pressed\n";
							MainMenu.close();
							foo();

							break;
						case 1:
							cout << "vcpu pressed\n";
							MainMenu.close();
							vscpu();
							break;
						case 2:
							cout << "exit pressed\n";
							MainMenu.close();
							break;
						default:
							break;
					}
				}
			}
			MainMenu.clear();
			MainMenu.draw(mainMenu[0]);
			MainMenu.draw(mainMenu[1]);
			MainMenu.draw(mainMenu[2]);
			MainMenu.display();
		}
	}
}
