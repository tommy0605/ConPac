#pragma once
#include "Map.h"

class Gost;
class PMan
{
public:
	int x;
	int y;
	bool bc;
	bool doa;
	int mapnum;
	int life;
	int score;
	PMan();
	~PMan();
	void Move(Map* map, Gost* g);
	bool CheckThing(char key, int x, int y, Map* map, Gost* g);
	int LifeCheck(Map* map);
	int GetScore();

	


private:
	
	//TODO::키를 한번 누르면 계속 진행되게 해야함

};

