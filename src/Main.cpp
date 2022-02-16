#include "Platform/Platform.hpp"
#include <iostream>
using namespace util;
using namespace std;
using namespace sf;

int main()
{

#if defined(_DEBUG)
	// command line
#endif
	int socket[14];
	RenderWindow window(VideoMode(512, 512), "Bantumi", Style::Close | Style::Resize);
	//Creating blocks
	RectangleShape player(Vector2f(100.0f, 100.0f));

	void draw(RenderWindow * window);

	player.setFillColor(Color::Blue);

	Event evnt;

	while (window.isOpen())
	{

		while (window.pollEvent(evnt))
		{
			//Manage events
			switch (evnt.type)
			{
				case Event::Closed:
					window.close();
					break;

				case Event::Resized:
					cout << "New window width: " << evnt.size.width << ", New window height: " << evnt.size.height << endl;
					break;
				default:
					break;
			}

			if (Mouse::isButtonPressed(Mouse::Left))
			{
				Vector2i mousePos = Mouse::getPosition(window);
				player.setPosition((float)mousePos.x, (float)mousePos.y);
			}
		}

		window.draw(player);
		window.display();
	}

	return 0;
}
