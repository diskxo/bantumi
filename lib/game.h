#include "Platform/Platform.hpp"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <time.h>

using namespace sf;

void versus(int mode);
int manageTurn(int sockets[], int turn, int l);
int cpuBrain(int sockets[]);
int checkWin(int sockets[], int nBeans);
//void manageWin(int winner, sf::RenderWindow* screen);
