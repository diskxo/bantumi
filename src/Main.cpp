#include "Platform/Platform.hpp"
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

#if defined(_DEBUG)
	// command line
#endif

	// create window
	RenderWindow window(VideoMode(1024, 720), "Bantumi", Style::Close);

	// inititialize time random seed
	srand(time(NULL));
	int eachBean = rand() % 6 + 3;

	// load background
	Texture texture;
	texture.loadFromFile("./src/assets/background.jpg");
	Sprite sprite;
	// this is where you add an & to designate texture as a pointer
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	float xPos = (float)1024 / 2;
	float yPos = (float)720 / 2;
	sprite.setPosition(xPos, yPos);

	// define sockets
	sf::RectangleShape socket[14];
	// define counter text
	sf::Text counterText[14];
	// define font
	sf::Font font;
	font.loadFromFile("./src/assets/fonts/Roboto-Black.ttf");

	// define value of sockets
	/*int socketValue[13];
	// start all elements with a value of 6
	for (int i = 0; i < 14; i++)
	{
		socketValue[i] = 6;
	}*/

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
		// draw texture
		window.draw(sprite);

		// draw sockets, barns and bean counters
		for (int l = 0, pos = 83; l < 14; l++, pos += 150)
		{

			socket[l].setSize(sf::Vector2f(100, 100));
			socket[l].setFillColor(Color::Blue);
			socket[l].setOutlineThickness(1.0f);

			if (l < 6)
			{
				// draw enemy sockets
				socket[l].setPosition(Vector2f(pos, 100));
			}
			else if (l < 13 && l > 6)
			{
				// draw ally sockets
				socket[l].setPosition(Vector2f(pos, 500));
			}
			else if (l == 6)
			{
				// draw enemy barn
				socket[l].setPosition(Vector2f(83, 300));
				pos = -67;
			}
			else if (l == 13)
			{
				// draw ally barn
				socket[l].setPosition(Vector2f(833, 300));
			}

			window.draw(socket[l]);

			// counters settings
			counterText[l].setFont(font);
			counterText[l].setString(to_string(eachBean));
			counterText[l].setCharacterSize(20);

			sf::FloatRect rectBounds = socket[l].getGlobalBounds();
			sf::FloatRect textBounds = counterText[l].getGlobalBounds();

			counterText[l].setPosition(
				rectBounds.left + (rectBounds.width / 2) - (textBounds.width / 2),
				rectBounds.top + (rectBounds.height / 2) - textBounds.height);

			counterText[l].setFillColor(sf::Color::White);
			window.draw(counterText[l]);
		}

		// end the current frame and display its contents on screen
		window.display();
	}

	return 0;
}
