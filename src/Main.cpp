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

	// create window
	RenderWindow window(VideoMode(1024, 720), "Bantumi", Style::Close);

	// load background
	/*
	Texture texture;
	texture.loadFromFile("./src/background.jpg");
	Sprite sprite;
	Vector2u size = texture.getSize();
	sprite.setTexture(texture); //This is where you add an & to designate texture as a pointer
	sprite.setOrigin(size.x / 2, size.y / 2);
	*/

	// define sockets
	sf::RectangleShape enemySocket[6], allySocket[6], barnEnemy, barnAlly;

	void draw(RenderWindow * window);
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

				default:
					break;
			}
		}
		// clear the whole window before rendering a new frame
		window.clear();

		// draw enemy sockets
		for (int l = 0, pos = 83; l < 6; l++, pos += 150)
		{
			enemySocket[l].setSize(sf::Vector2f(100, 100));
			enemySocket[l].setPosition(sf::Vector2f(pos, 100));
			enemySocket[l].setFillColor(Color::Blue);
			window.draw(enemySocket[l]);
		}

		// draw ally sockets
		for (int l = 0, pos = 83; l < 6; l++, pos += 150)
		{
			allySocket[l].setSize(sf::Vector2f(100, 100));
			allySocket[l].setPosition(sf::Vector2f(pos, 500));
			allySocket[l].setFillColor(Color::Blue);
			window.draw(allySocket[l]);
		}

		// end the current frame and display its contents on screen
		window.display();
	}

	return 0;
}
