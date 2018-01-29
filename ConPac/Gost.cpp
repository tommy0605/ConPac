#include "Gost.h"
#include "PMan.h"



Gost::Gost()
{
	x = 0;
	initx = 0;
	y = 0;
	inity = 0;
	mapnum = GOST;
	doa = true;
	Tmap = BLANK;
	fon = false;
}


Gost::~Gost()
{
}

void Gost::Move(Map * map, PMan* pac)
{

	int k = rand() % 4;
	char key;
	int xx = this->x;
	int yy = this->y;
	switch (k)
	{
		case 0:
			key = 'w';
			break;
		case 1:
			key = 's';
			break;
		case 2:
			key = 'a';
			break;
		case 3:
			key = 'd';
			break;
	}

	if (fon == false)
	{
		if (CheckThing(key, xx, yy, map, pac) == true)
			map->mapi[y][x] = Tmap;
	}
	
	switch (key)
	{
		case 'w':
			if (CheckThing(key, xx, yy, map, pac) == true)
				this->y--;
			break;
		case 's':
			if (CheckThing(key, xx, yy, map, pac) == true)
				this->y++;
			break;
		case 'a':
			if (CheckThing(key, xx, yy, map, pac) == true)
				this->x--;
			break;
		case 'd':
			if (CheckThing(key, xx, yy, map, pac) == true)
				this->x++;
			break;
	}
	if (fon == false)
	{
		if (CheckThing(key, xx, yy, map, pac) == true)
			Tmap = map->mapi[y][x];
	}
}

bool Gost::CheckThing(char key, int x, int y, Map * map, PMan * pac)
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
	if (map->mapi[y][x] == MINICOO || map->mapi[y][x] == BLANK || map->mapi[y][x] == BIGCOO )
	{
		if (map->mapi[y][x] == PACMAN)
		{
			if (pac->bc == true)
				doa = false;
			else
				doa = false;
		}
		return true;
	}
	else if (map->mapi[y][x] == PACMAN)
	{
		if (map->mapi[y][x] == PACMAN)
		{
			if (pac->bc == true)
				doa = false;
			else
				doa = false;
		}
		return false;
	}
	else
		return false;

}

void Gost::CheckPacXY(int x, int y)
{
	if (this->x == x && this->y == y)
		doa = false;
}



void Gost::DOACheck()
{
	if (doa == false)
	{
		x = initx;
		y = inity;
		doa = true;
	}
}

void Gost::SetXY(int xx, int yy)
{
	initx = xx;
	inity = yy;
	x = initx;
	y = inity;
}

