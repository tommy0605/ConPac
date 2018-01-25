#include "PManager.h"
#include "Gost.h"
#include "PMan.h"



PManager::PManager(Map* map, PMan* pac, Gost* g)
{
	this->map = map;
	this->pac = pac;
	this->g = g;
	score = 0;
	highscore = 0;
	coin = 0;
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
	map->InputPac(pac);
	g[0].SetXY(12, 15);
	g[1].SetXY(13, 15);
	g[2].SetXY(14, 15);
	g[3].SetXY(15, 15);
	for (int i = 0; i < 4; i++)
		map->InputGost(&g[i]);

	while (true)
	{
		Sleep(500);
		system("cls");

		map->DrawMap(pac);
		pac->Move(map);
		for (int i = 0; i < 4; i++)
		{
			g[i].DOACheck();
			g[i].Move(map, pac);
		}
		if (CheckCoin() == false)
		{
			map->MapInit();
			Sleep(3000);
			break;
		}
		score = pac->GetScore();
		cout << "Score : " << score << endl;
	}
}

void PManager::ShowHigh()
{
	cout << "HighScore : " << highscore << endl;
}

bool PManager::CheckCoin()
{
	if (pac->LifeCheck() == 0)
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
}
