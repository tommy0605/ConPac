#include "Map.h"
#include "PMan.h"
#include "Gost.h"
#include "PManager.h"


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
	for (int i = 0; i < HEIGHT; i++)
		for (int j = 0; j < WIDETH; j++)
		{
			mapb[i][j] = mapi[i][j];
		}
}


Map::~Map()
{
}

void Map::DrawMap(PMan* pac)
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDETH; j++)
		{
			switch (mapi[i][j])
			{
				case WALL:
					cout << "¡á";
					break;
				case BIGCOO:
					cout << "¡Ú";
					break;
				case MINICOO:
					cout << "¡¤";
					break;
				case PACMAN:
					if (pac->bc == true)
						cout << "¡Ý";
					else
						cout << "¡Ü";
					break;
				case GOST:
					cout << "£À";
					break;
				case BLANK:
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

bool Map::CheckClaer()
{
	for(int i = 0;i <HEIGHT;i++)
		for (int j = 0; j < WIDETH; j++)
		{
			if (mapi[i][j] == MINICOO || mapi[i][j] == BIGCOO)
				return false;
		}
	return true;
}

void Map::MapInit()
{
	for (int i = 0; i < HEIGHT; i++)
		for (int j = 0; j < WIDETH; j++)
		{
			mapi[i][j] = mapb[i][j];
		}
}
