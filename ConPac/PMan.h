#pragma once
#include "Map.h"
#include "Gost.h"

class PMan
{
public:
	int x;
	int y;
	bool bc;
	int mapnum;
	PMan();
	~PMan();
	void Move();
	bool CheckMap(Map* map);
	bool CheckGost(Gost* g);
	


private:
	int life;
	bool doa;
	
	//TODO::키를 한번 누르면 계속 진행되게 해야함

};

