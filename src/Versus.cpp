#include "Platform/Platform.hpp"
#include <Game.h>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace util;
using namespace std;
using namespace sf;

void versus(int mode)
{
	// create window
	RenderWindow window(VideoMode(1024, 720), "Bantumi", Style::Close);

	// inititialize time random seed
	srand(time(NULL));
	int eachBean = rand() % 4 + 3;

	// load background
	Texture texture;
	texture.loadFromFile("./src/assets/background.jpg");
	Sprite sprite;
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	float xPos = (float)1024 / 2;
	float yPos = (float)720 / 2;
	sprite.setPosition(xPos, yPos);

	// define value of sockets
	int socketValue[14];
	// initialize all elements with the random value and barns with o
	for (int i = 0; i < 14; i++)
	{
		socketValue[i] = eachBean;
		switch (i)
		{
			case 6:
				socketValue[i] = 0;
				break;
			case 13:
				socketValue[i] = 0;
				break;
			default:
				break;
		}
	}

	// define sockets
	sf::RectangleShape socket[14];
	// define counter text
	sf::Text counterText[14];
	// define font
	sf::Font font;
	font.loadFromFile("./src/assets/fonts/ArcadeClassic.ttf");

	void draw(RenderWindow * window);
	Event evnt;

	// set player turn
	int turn = 0;

	// circle player turn
	CircleShape playerTurn(20);
	playerTurn.setFillColor(Color::Blue);
	playerTurn.setPosition(Vector2f(30, 660));

	int winner = 0;
	while (window.isOpen())
	{

		while (window.pollEvent(evnt))
		{
			// manage events
			switch (evnt.type)
			{
				case Event::Closed:
					window.close();
					break;
				case Event::MouseButtonPressed:

					if (evnt.mouseButton.button == sf::Mouse::Left)
					{
						auto mouse_pos = Mouse::getPosition(window);
						auto translated_pos = window.mapPixelToCoords(mouse_pos);

						for (int l = 0; l < 14; l++)
						{
							if (socket[l].getGlobalBounds().contains(translated_pos))
							{
								turn = manageTurn(socketValue, turn, l);
							}
						}
					}
					break;

				default:
					break;
			}

			int step;
			if (mode == 1 && turn == 1)
			{
				step = cpuBrain(socketValue);
				turn = manageTurn(socketValue, turn, step);
			}

			// set player turn circle
			if (turn == 0)
				playerTurn.setPosition(Vector2f(30, 660));
			else
				playerTurn.setPosition(Vector2f(30, 30));

			window.draw(playerTurn);

			winner = checkWin(socketValue, eachBean);
			if (winner != 0)
			{
				// win content
				Text winText;
				cout << "Player" << winner << " wins!\n";
				Text winnerText;
				FloatRect textRect = winText.getLocalBounds();
				winText.setFont(font);
				winText.setString("Player wins!");
				winText.setCharacterSize(60);
				winText.setOrigin(textRect.left + textRect.width / 2.0f,
					textRect.top + textRect.height / 2.0f);
				winText.setPosition(sf::Vector2f(1024 / 2.0f, 720 / 2.0f));
				window.draw(winText);
			}
		}
		// draw texture, player turn and winner text
		window.draw(sprite);
		window.draw(playerTurn);

		// draw sockets, barns and bean counters
		for (int l = 0, pos = 83, initpos = 833; l < 14; l++, pos += 150, initpos -= 150)
		{
			socket[l].setSize(sf::Vector2f(100, 100));
			socket[l].setFillColor(Color::Blue);
			socket[l].setOutlineThickness(1.0f);

			if (l < 6)
			{
				// draw enemy sockets
				socket[l].setPosition(Vector2f(initpos, 100));
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
			counterText[l].setString(to_string(socketValue[l]));
			counterText[l].setCharacterSize(40);

			sf::FloatRect rectBounds = socket[l].getGlobalBounds();
			sf::FloatRect textBounds = counterText[l].getGlobalBounds();

			// set counters to center
			counterText[l].setPosition(
				rectBounds.left + (rectBounds.width / 2) - (textBounds.width / 2),
				rectBounds.top + ((rectBounds.height / 2) - 10) - textBounds.height);

			counterText[l].setFillColor(sf::Color::White);
			window.draw(counterText[l]);
		}

		window.display();
	}
}
