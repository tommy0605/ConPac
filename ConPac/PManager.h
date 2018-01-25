#pragma once
#include "Map.h"


class PManager
{
public:
	int score;
	int highscore;
	int coin;
	bool first;
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
	//TODO::동전넣기 동전당 목숨3개
	//TODO::메뉴
	//TODO::점수 기록
private:
	Map* map;
	PMan* pac;
	Gost* g;
};

