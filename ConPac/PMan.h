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
	
	//TODO::Ű�� �ѹ� ������ ��� ����ǰ� �ؾ���

};

