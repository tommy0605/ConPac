#pragma once
#include "Map.h"


class PManager
{
public:
	int score;
	int highscore;
	int coin;
	PManager(Map* map, PMan* pac, Gost* g);
	~PManager();
	void UI();
	void Gamestart();
	void SetHigh()
	{
		if (score > highscore)
			highscore = score;
	}
	void ShowHigh();
	bool CheckCoin();
	//TODO::�����ֱ� ������ ���3��
	//TODO::�޴�
	//TODO::���� ���
private:
	Map* map;
	PMan* pac;
	Gost* g;
};

