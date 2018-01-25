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

void PMan::Move(Map* map)
{
	
	if (kbhit())
	{	
		char key = getch();
		map->mapi[y][x] = BLANK;
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
			case GOST: 
				if (bc == true)
					doa = false;
				doa = false;  break;
			case BIGCOO:  score += 10;
				bc = true;
				map->mapi[y][x] = PACMAN; break;
			case MINICOO:  score += 3;
				map->mapi[y][x] = PACMAN; break;
			case WALL: 
				map->mapi[y][x] = WALL;
				x = fx;
				y = fx;
				map->mapi[y][x] = PACMAN; break;
			default:    map->mapi[y][x] = PACMAN; break;
		}

	}

}

int PMan::LifeCheck()
{
	if (doa == false)
	{
		Sleep(1000);
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
