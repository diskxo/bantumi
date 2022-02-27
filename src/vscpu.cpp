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

int cpuBrain(int sockets)
{
	int counter = 0;
	for (int i = 7; i < 13; i++)
	{
		// check if there is a move that allows to steal beans from the opponent
		int counter = sockets[i];
		if (sockets[i + counter] == 0 && sockets[])
		{
		}
	}
}

void vscpu()
{

#if defined(_DEBUG)
	// command line
#endif

	// create window
	RenderWindow window(VideoMode(1024, 720), "Bantumi", Style::Close);

	// inititialize time random seed
	srand(time(NULL));
	int eachBean = rand() % 4 + 3;

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

	//int barnAlly = 0, barnEnemy = 0;
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
	font.loadFromFile("./src/assets/fonts/Roboto-Black.ttf");

	void draw(RenderWindow * window);
	Event evnt;

	// set player turn
	int turn = 0;

	// circle player turn
	CircleShape playerTurn(20);
	playerTurn.setFillColor(Color::Blue);
	playerTurn.setPosition(Vector2f(30, 660));

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

						auto mouse_pos = sf::Mouse::getPosition(window);
						auto translated_pos = window.mapPixelToCoords(mouse_pos);

						for (int l = 0; l < 14; l++)
						{
							if (turn == 0)
							{
								if (socket[l].getGlobalBounds().contains(translated_pos))
								{
									if (l > 6 && l != 13)
									{
										// check if the ultimate bean goes into a 0 socket
										if (socketValue[l + socketValue[l]] == 0 && l + socketValue[l] < 13 && l + socketValue[l] > 6)
										{
											socketValue[13] += socketValue[12 - l];
											socketValue[12 - (l + socketValue[l])] = 0;
										}

										for (int i = socketValue[l], c = 1, c1 = 0; socketValue[l] != 0; i++, c++, socketValue[l]--)
										{
											if ((l + c) > 13)
											{
												if (c1 == 6)
												{
													c1++;
												}
												socketValue[c1]++;
												c1++;
												turn = 1;
											}
											else
											{
												// check if the ultimate bean goes into the barn
												socketValue[l + c]++;
												if (l + c == 13)
												{
													turn = 0;
												}
												else
												{
													turn = 1;
												}
											}
										}
									}
								}
							}
							else
							{
								cpuBrain(socketValue);
							}
						}
						// set player turn
						if (turn == 0)
						{

							playerTurn.setPosition(Vector2f(30, 660));
						}
						else
						{
							playerTurn.setPosition(Vector2f(30, 30));
						}

						window.draw(playerTurn);

						// check wins
						int totalValueAlly = 0;
						int totalValueEnemy = 0;
						for (int i = 0; i < 6; i++)
						{
							totalValueAlly += socketValue[i];
						}
						if (totalValueAlly == 0)
						{
							cout << "Player 2 wins!\n";
						}
						else if (socketValue[6] > (eachBean * 12) / 2)
						{
							cout << "Player 2 wins!\n";
						}

						for (int i = 7; i < 13; i++)
						{
							totalValueEnemy += socketValue[i];
						}
						if (totalValueEnemy == 0)
						{
							cout << "Player 1 wins!\n";
						}
						else if (socketValue[13] > (eachBean * 12) / 2)
						{
							cout << "Player 1 wins!\n";
						}
					}
					break;

				default:
					break;
			}
		}
		// draw texture
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
}
