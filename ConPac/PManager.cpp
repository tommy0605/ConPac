#include "PManager.h"
#include "Gost.h"
#include "PMan.h"
#include "Draw.h"



PManager::PManager(Map* map, PMan* pac, Gost* g, Draw* draw)
{
	this->map = map;
	this->pac = pac;
	this->g = g;
	this->draw = draw;
	score = 0;
	highscore = 0;
	coin = 0;
	first = true;
}


PManager::~PManager()
{
}

void PManager::UI()
{
	while (true)
	{
		cout << "Welcome to PACMAN" << endl << endl;
		int key;
		cout << "1.Game Start, 2.HighScore, 3.Insert Coin 4.Exit" << endl;
		cin >> key;
		switch (key)
		{
			case 1:
				if (coin == 0)
					cout << "Insert Coin First" << endl;
				else
					Gamestart();
				break;
			case 2:
				ShowHigh();
				continue;
				break;
			case 3:
				coin++;
				cout << "coin : " << coin << endl;
				continue;
				break;
			case 4:
				return;
				break;

		}
	}
}

void PManager::Gamestart()
{
	g[0].SetXY(12, 15);
	g[1].SetXY(13, 15);
	g[2].SetXY(14, 15);
	g[3].SetXY(15, 15);
	draw->CreateBuffer(WIDETH * 2, HEIGHT);

	while (true)
	{
		Sleep(500);
		
	
		pac->InputMove();
		map->InputPac(pac, g);
		for (int i = 0; i < 4; i++)
		{
			g[i].DOACheck();
			map->InputGost(&g[i], pac);
		}
		pac->Move(map, g);
		map->DrawMap(pac, draw);
		if (CheckCoin() == false)
		{
			map->MapInit();
			cout << "GAME CLEAR!!" << endl;
			Sleep(3000);
			break;
		}
		score = pac->GetScore();
		cout << "Score : " << score << endl;
		draw->Clear();
		draw->Print();
		draw->Flipping();
	
	}
}

void PManager::ShowHigh()
{
	cout << "HighScore : " << highscore << endl;
}

bool PManager::CheckCoin()
{
	if (pac->LifeCheck(map) == 0)
	{
		if (coin > 0)
		{
			coin--;
			pac->life = 3;
			return true;
		}
		else
		{
			cout << "GAME OVER" << endl;
			return false;
		}
	}
	return true;
}
