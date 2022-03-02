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

int manageTurn(int sockets[], int turn, int l)
{
	if (turn == 0)
	{
		if (l > 6 && l != 13)
		{
			// check if the ultimate bean goes into a 0 socket
			if (sockets[l + sockets[l]] == 0 && l + sockets[l] > 6 && l + sockets[l] < 13)
			{
				sockets[13] += sockets[12 - (l + sockets[l])];
				sockets[12 - (l + sockets[l])] = 0;
			}

			for (int i = sockets[l], c = 1, c1 = 0; sockets[l] != 0; i++, c++, sockets[l]--)
			{
				if ((l + c) > 13)
				{
					if (c1 == 6)
					{
						c1++;
					}
					sockets[c1]++;
					c1++;
					turn = 1;
				}
				else
				{
					// check if the ultimate bean goes into the barn
					sockets[l + c]++;
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
	else if (turn == 1)
	{
		if (l < 6)
		{
			// check if the ultimate bean goes into a 0 socket
			if (sockets[l + sockets[l]] == 0 && l + sockets[l] < 6)
			{
				sockets[6] += sockets[12 - (l + sockets[l])];
				sockets[12 - (l + sockets[l])] = 0;
			}

			// increments the value of the next sockets
			for (int i = sockets[l], c = 1, c1 = 0; sockets[l] != 0; i++, c++, sockets[l]--)
			{
				if (l + c > 13)
				{
					if (c1 == 13)
					{
						c1++;
					}
					sockets[c1]++;
					c1++;
					turn = 0;
				}
				else
				{
					if (l + c == 13)
					{
						c++;
					}
					sockets[l + c]++;
					// check if the ultimate bean goes into the barn
					if (l + c == 6)
					{
						turn = 1;
					}
					else
					{
						turn = 0;
					}
				}
			}
		}
	}

	return turn;
}

int cpuBrain(int sockets[14])
{

	int move = 0;
	for (int i = 0; i < 6; i++)
	{
		sockets[i] = sockets[i];

		if (i + sockets[i] == 6)
		{
			move = i;
			return move;
		}

		// checks if there is a move that allows to steal beans from the opponent
		if (sockets[i + sockets[i]] == 0 && i + sockets[i] < 6 && sockets[12 - (i + sockets[i])] > 0 && sockets[i] > 0)
		{
			move = i;
			return move;
		}
	}

	for (int i = 0; i < 6; i++)
	{
		// predicts whether the opponent will be able to steal the beans
		for (int x = 7; x < 13; x++)
		{
			// checks if the opponent can steal ally beans
			if (sockets[x + sockets[x]] == 0 && x + sockets[x] < 13 && sockets[x] > 0 && sockets[12 - (x + sockets[x])] > 0)
			{
				move = 12 - (x + sockets[x]);
				return move;
			}
		}
	}

	// if there isn't any move available
	for (int i = 0; i < 6; i++)
	{
		sockets[i] = sockets[i];
		if (i + sockets[i] > 5)
		{
			move = i;
			return move;
		}
	}
	for (int i = 5; i > 0; i--)
	{
		if (sockets[i] != 0)
		{
			move = i;
			return move;
		}
	}
	return move;
}

int checkWin(int sockets[], int nBeans)
{
	int winner = 0;
	int totalValueAlly = 0;
	int totalValueEnemy = 0;
	for (int i = 0; i < 6; i++)
	{
		totalValueAlly += sockets[i];
		totalValueEnemy += sockets[i + 7];
	}
	if (totalValueAlly == 0)
	{
		winner = 1;
	}
	else if (sockets[6] > (nBeans * 12) / 2)
	{
		winner = 2;
	}

	if (totalValueEnemy == 0)
	{
		winner = 1;
	}
	else if (sockets[13] > (nBeans * 12) / 2)
	{
		winner = 1;
	}
	return winner;
}
