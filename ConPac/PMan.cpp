#include "PMan.h"
#include "PManager.h"
#include "Gost.h"


PMan::PMan()
{
	x = 14;
	y = 23;
	life = 3;
	doa = false;
	bc = false;
	mapnum = PACMAN;
	score = 0;

}


PMan::~PMan()
{
}

void PMan::Move(Map * map, Gost * g)
{
	int xx = this->x;
	int yy = this->y;

	switch (key)
	{
		case 'w':
			if (CheckThing(key, xx, yy, map, g) == true)
				this->y--;
			break;
		case 's':
			if (CheckThing(key, xx, yy, map, g) == true)
				this->y++;
			break;
		case 'a':
			if (CheckThing(key, xx, yy, map, g) == true)
				this->x--;
			break;
		case 'd':
			if (CheckThing(key, xx, yy, map, g) == true)
				this->x++;
			break;
	}
	if (CheckThing(key, xx, yy, map, g) == true)
		map->mapi[yy][xx] = BLANK;
}

void PMan::InputMove()
{
	if (kbhit())
	{
		key = getch();
	}
}

bool PMan::CheckThing(char key, int x, int y, Map * map, Gost* g)
{
	switch (key)
	{
		case 'w':
			y--;
			break;
		case 's':
			y++;
			break;
		case 'a':
			x--;
			break;
		case 'd':
			x++;
			break;
	}
	if (map->mapi[y][x] == MINICOO || map->mapi[y][x] == BLANK || map->mapi[y][x] == BIGCOO)
	{
		switch (map->mapi[y][x])
		{
			case MINICOO:
				score += 10;
				return true;
				break;
			case BLANK:
				return true;
				break;
			case BIGCOO:
				bc = true;
				score += 20;
				return true;
				break;


		}
		return true;
	}
	else if (map->mapi[y][x] == GOST)
	{
		if (bc == true)
		{
			for(int i =0;i<4;i++)
				g[i].CheckPacXY(x, y);
		}
		else
			doa = false;
		return false;
	}
	else
		return false;
}



int PMan::LifeCheck(Map* map)
{
	if (doa == false)
	{
		cout << "PACMAN GOT EATEN" << endl;
		map->mapi[y][x] = BLANK;
		Sleep(100);

		x = 14;
		y = 23;
		life--;
		doa = true;
		return life;
	}
	else
	return life;
}

int PMan::GetScore()
{
	return score;
}
