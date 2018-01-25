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
}


Gost::~Gost()
{
}

void Gost::Move(Map * map, PMan* pac)
{

	int ikey = rand() %4;
	char key;
	switch (ikey)
	{
		case 0:key = 'w'; break;
		case 1:key = 's'; break;
		case 2:key = 'a'; break;
		case 3:key = 'd'; break;
	}
	int tmap = map->mapi[y][x];
	int fx = x;
	int fy = y;

	if (key == 'w')
		y--;
	else if (key == 's')
		y++;
	else if (key == 'a')
		x--;
	else if (key == 'd')
		x++;

	switch (map->mapi[y][x])
	{
		case PACMAN: 
			if (pac->bc == true)
				doa = false;
			else
				pac->doa = false;
			break;
		case BIGCOO:
			map->mapi[fy][fx] = tmap;
			map->mapi[y][x] = GOST; break;
		case BLANK:
			map->mapi[fy][fx] = tmap;
			map->mapi[y][x] = GOST; break;
		case MINICOO:
			map->mapi[fy][fx] = tmap;
			map->mapi[y][x] = GOST; break;
		case WALL:
			map->mapi[y][x] = WALL;
			x = fx;
			y = fx;
			map->mapi[y][x] = GOST; break;
		case GOST:  x = fx;
			y = fx;
			map->mapi[y][x] = GOST; break;
		default:    map->mapi[y][x] = GOST; break;
	}
	map->mapi[fy][fx] = tmap;
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

