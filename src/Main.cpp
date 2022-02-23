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
	sf::RectangleShape enemySocket[6], allySocket[6], barnEnemy, barnAlly;
	// define counter text
	sf::Text counterText[14];
	// define font
	sf::Font font;
	font.loadFromFile("./src/assets/fonts/Roboto-Black.ttf");

	// define value of sockets
	/*int socketValue[14];
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
		// draw enemy sockets
		for (int l = 0, pos = 83; l < 6; l++, pos += 150)
		{
			enemySocket[l].setSize(sf::Vector2f(100, 100));
			enemySocket[l].setPosition(sf::Vector2f(pos, 100));
			enemySocket[l].setFillColor(Color::Blue);
			enemySocket[l].setOutlineThickness(1.0f);
			window.draw(enemySocket[l]);
		}

		// draw ally sockets
		for (int l = 0, pos = 83; l < 6; l++, pos += 150)
		{
			allySocket[l].setSize(sf::Vector2f(100, 100));
			allySocket[l].setPosition(sf::Vector2f(pos, 500));
			allySocket[l].setFillColor(Color::Blue);
			allySocket[l].setOutlineThickness(1.0f);
			window.draw(allySocket[l]);
		}

		// insert text counter in all of the sockets
		for (int l = 0; l < 6; l++)
		{
			counterText[l].setFont(font); // font is a sf::Font

			counterText[l].setString("1");
			counterText[l].setCharacterSize(20);

			sf::FloatRect rectBounds = enemySocket[l].getGlobalBounds();
			sf::FloatRect textBounds = counterText[l].getGlobalBounds();

			counterText[l].setPosition(
				rectBounds.left + (rectBounds.width / 2) - (textBounds.width / 2),
				rectBounds.top + (rectBounds.height / 2) - textBounds.height);

			counterText[l].setFillColor(sf::Color::White);
			window.draw(counterText[l]);
		}
		for (int l = 0; l < 6; l++)
		{
			counterText[l].setFont(font); // font is a sf::Font

			counterText[l].setString("1");
			counterText[l].setCharacterSize(20);

			sf::FloatRect rectBounds = allySocket[l].getGlobalBounds();
			sf::FloatRect textBounds = counterText[l].getGlobalBounds();

			counterText[l].setPosition(
				rectBounds.left + (rectBounds.width / 2) - (textBounds.width / 2),
				rectBounds.top + (rectBounds.height / 2) - textBounds.height);

			counterText[l].setFillColor(sf::Color::White);
			window.draw(counterText[l]);
		}

		// draw barns
		barnEnemy.setSize(sf::Vector2f(100, 100));
		barnEnemy.setPosition(sf::Vector2f(83, 300));
		barnEnemy.setFillColor(Color::Red);
		barnEnemy.setOutlineThickness(1.0f);
		window.draw(barnEnemy);

		barnAlly.setSize(sf::Vector2f(100, 100));
		barnAlly.setPosition(sf::Vector2f(833, 300));
		barnAlly.setFillColor(Color::Red);
		barnAlly.setOutlineThickness(1.0f);
		window.draw(barnAlly);
		// end the current frame and display its contents on screen
		window.display();
	}

	return 0;
}
