#include "Platform/Platform.hpp"
#include <mainMenu/MainMenu.hpp>

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
	// create window
	RenderWindow window(VideoMode(1024, 720), "Bantumi", Style::Close);

	MainMenu mainmenu(1024, 720);

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::Up)
				{
					mainmenu.moveUp();
					break;
				}
				if (event.key.code == Keyboard::Down)
				{
					mainmenu.moveDown();
					break;
				}
				if (event.key.code == Keyboard::Return)
				{
					int x = mainmenu.mainMenuPressed();
					if (x == 0)
					{
						cout << "v1 pressed\n";
					}
					if (x == 1)
					{
						cout << "vcpu pressed\n";
					}
					if (x == 2)
					{
						cout << "exit pressed\n";
					}
				}
			}
			window.clear();
			mainmenu.Draw(window);
			window.display();
		}
	}
}