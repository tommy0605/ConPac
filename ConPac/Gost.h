#pragma once
#include "Map.h"
#include "PMan.h"

class Gost
{
public:
	int x;
	int y;
	int mapnum;

	Gost();
	~Gost();
	//TODO::���ɵ� ����(���������ϸ�)
	bool CheckMap(Map* map);
	bool CheckPac(PMan* pac);
	bool CheckAG(Gost* g);

	
protected:
	bool doa;

};

