#pragma once
#include "Map.h"
#include <conio.h>

void PacMove()
{
	char key = getch();
	int x = p->x;
	int y = p->y;
	if (kbhit)
	{
		switch (key)
		{
			case 'w':
				if(CheckThing(key, x, y) == true)
					p->y--;
				break;
			case 's':
				if (CheckThing(key, x, y) == true)
					p->y++;
				break;
			case 'a':
				if (CheckThing(key, x, y) == true)
					p->x--;
				break;
			case 'd':
				if (CheckThing(key, x, y) == true)
					p->x++;
				break;
		}
	}
	if (CheckThing(key, x, y) == true)
		map[y][x] = BLANK;

}

bool PCheckThing(char key, int x, int y)
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
	if (map[y][x] == MINICOO || map[y][x] == BLANK || map[y][x] == BIGCOO)
	{
		switch (map[y][x])
		{
			case MINICOO:
				p->score += 10;
				return true;
				break;
			case BLANK:
				return true;
				break;
			case BIGCOO:
				p->bc = true;
				p->score += 20;
				return true;
				break;


		}
		return true;
	}
	else if (map[y][x] == GOST)
	{
		if (p->bc == true)
			g->doa = false;
		else
			p->doa = false;
	}
	else
		return false;

}

void GMove()
{

	char key;
	int x = g->x;
	int y = g->y;
	if (kbhit)
	{
		switch (key)
		{
			case 'w':
				if (CheckThing(key, x, y) == true)
					p->y--;
				break;
			case 's':
				if (CheckThing(key, x, y) == true)
					p->y++;
				break;
			case 'a':
				if (CheckThing(key, x, y) == true)
					p->x--;
				break;
			case 'd':
				if (CheckThing(key, x, y) == true)
					p->x++;
				break;
		}
	}
	if (CheckThing(key, x, y) == true)
		map[y][x] = BLANK;

}

bool GCheckThing(char key, int x, int y)
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
	if (map[y][x] == MINICOO || map[y][x] == BLANK || map[y][x] == BIGCOO || map[y][x] == PACMAN)
	{
		if (map[y][x] == PACMAN)
		{
			if (pac->bc == true)
				g->doa = false;
			else
				p->doa = false;
		}
		return true;
	}
	else
		return false;


}

