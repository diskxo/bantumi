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

int cpuBrain(int sockets[14])
{
	int counterAlly = 0;
	int counterOpponent = 0;
	for (int i = 0; i < 6; i++)
	{
		// i == contatore da 0 a 6
		// counter == prende il valore contenuto nell'array socket
		// socket[i + counter] == prende il valore dell'array che si trova se l'array i viene sommato
		// i + counter == prende il valore del numero dell'array che si ottiene se viene cliccato il primo

		// predicts whether the opponent will be able to steal the beans
		for (int x = 7; x < 13; x++)
		{
			counterOpponent = sockets[x];
			if (sockets[x + counterOpponent] == 0 && x + counterOpponent < 13)
			{
				// checks if it is possible to prevent the opponent from stealing the beans
				if (sockets[i + counterOpponent] >= x + counterOpponent)
				{
					if (sockets[12 - (x + sockets[x])] > 0)
					{
						return i;
					}
				}
				// or it removes the beans that can be stolen
				else
				{
				}
			}
		}

		// check if there is a move that allows to steal beans from the opponent
		counterAlly = sockets[i];

		if (sockets[i + counterAlly] == 0 && i + counterAlly < 6 && sockets[12 - (i + counterAlly)] > 1)
		{
			return i;
		}
		else if (i + counterAlly == 6)
		{
			return i;
		}
		else if (i + counterAlly > 5)
		{
			return i;
		}
	}
	return 0;
}

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

			for (int i = sockets[l], c = 1; sockets[l] != 0; i++, c++, sockets[l]--)
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

	return turn;
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
