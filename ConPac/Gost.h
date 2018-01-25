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
	bool doa;
	int Tmap;
	bool fon;

	Gost();
	~Gost();
	//TODO::유령들 성격(구현가능하면)
	void Move(Map* map, PMan* pac);
	bool CheckThing(char key, int x, int y, Map* map, PMan* pac);
	void CheckPacXY(int x, int y);
	void DOACheck();
	void SetXY(int xx, int yy);


	
protected:

};

