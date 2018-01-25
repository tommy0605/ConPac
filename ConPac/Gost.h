#pragma once
#include "Map.h"


class PMan;
class Gost
{
public:
	int x;
	int initx;
	int y;
	int inity;
	int mapnum;

	Gost();
	~Gost();
	//TODO::유령들 성격(구현가능하면)
	void Move(Map* map, PMan* pac);
	void DOACheck();
	void SetXY(int xx, int yy);


	
protected:
	bool doa;

};

