#include "Map.h"
#include "PMan.h"
#include "Gost.h"



Map::Map()
{
	ifstream input("conmap.txt");
	string maps[HEIGHT];

	for (int i = 0; i < HEIGHT; i++)
		getline(input, maps[i]);;

	input.close();
	char imap[HEIGHT][WIDETH];
	for (int i = 0; i < HEIGHT; i++)
		for (int j = 0; j < WIDETH; j++)
		{
			imap[i][j] = maps[i][j];

		}
	for (int i = 0; i < HEIGHT; i++)
		for (int j = 0; j < WIDETH; j++)
		{
			mapi[i][j] = imap[i][j] - '0';
		}
}


Map::~Map()
{
}

void Map::DrawMap()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDETH; j++)
		{
			switch (mapi[i][j])
			{
				case 0:
					cout << "¡á";
					break;
				case 1:
					cout << "¡¡";
					break;
			}
		}
		cout << endl;
	}
}

void Map::InputPac(PMan * pac)
{
	int x = pac->x;
	int y = pac->y;
	mapi[y][x] = pac->mapnum;
}

void Map::InputGost(Gost * g)
{
	int x = g->x;
	int y = g->y;
	mapi[y][x] = g->mapnum;
}
