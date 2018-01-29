#include "Map.h"
#include "PMan.h"
#include "Gost.h"
#include "PManager.h"
#include "Draw.h"


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

void Map::DrawMap(PMan* pac, Draw* draw)
{
	string str;
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDETH; j++)
		{
			switch (mapi[i][j])
			{
				case WALL:
					str += "¡á";
					break;
				case BIGCOO:
					str += "¡Ú";
					break;
				case MINICOO:
					str += "¡¤";
					break;
				case PACMAN:
					if (pac->bc == true)
						str += "¡Ý";
					else
						str += "¡Ü";
					break;
				case GOST:
					str += "£À";
					break;
				case BLANK:
					str += "¡¡";
					break;
			}
		}
		str += "\n";
	}
	for (int i = 0; i < draw->size - 1; i++)
	{
		draw->map[i] = str[i];
	}

	draw->map[draw->size - 1] = NULL;
}

void Map::InputPac(PMan * pac, Gost * g)
{
	int x = pac->x;
	int y = pac->y;
	mapi[y][x] = pac->mapnum;
}

void Map::InputGost(Gost * g, PMan* pac)
{
	g->Move(this, pac);
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
