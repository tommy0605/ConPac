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
	char key;
	PMan();
	~PMan();
	void Move(Map* map, Gost* g);
	void InputMove();
	bool CheckThing(char key, int x, int y, Map* map, Gost* g);
	int LifeCheck(Map* map);
	int GetScore();

	


private:
	
	//TODO::Ű�� �ѹ� ������ ��� ����ǰ� �ؾ���

};

