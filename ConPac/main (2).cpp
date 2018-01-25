#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string>

#define MAPSIZE 20

#include "DoubleBuffering.h"
#include "Draw.h"
#include "Player.h"

using namespace std;

Player player;
Draw draw;

void PrintMap()
{
	string str;

	for (int i = 0; i < MAPSIZE; i++)
	{
		for (int j = 0; j < MAPSIZE; j++)
		{
			if (i == player.x && j == player.y)
			{
				str += "¡Û";
			}
			else {
				str += "¡Ú";
			}
		}
		str += "\n";
	}

	for (int i = 0; i < draw.size - 1; i++)
	{
		draw.map[i] = str[i];
	}

	draw.map[draw.size - 1] = NULL;
}

void main()
{
	draw.CreateBuffer(MAPSIZE * 2, MAPSIZE);

	while (true)
	{
		PrintMap();
		Sleep(500);
		player.Input();
		player.Move();
		draw.Clear();
		draw.Print();
		draw.Flipping();		
	}
}