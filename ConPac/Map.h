#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>

using namespace std;
#define WIDETH 28
#define HEIGHT 31

enum THINGS
{
	WALL,
	MINICOO, 
	BIGCOO,
	CHERRY, 
	BLANK, 
	PACMAN, 
	GOST
};

class PManager;
class PMan;
class Gost;
class Map
{
public:
	int mapi[HEIGHT][WIDETH];
	int mapb[HEIGHT][WIDETH];
	Map();
	~Map();
	void DrawMap(PMan* pac);
	void InputPac(PMan* pac, Gost * g);
	void InputGost(Gost* g, PMan* pac);
	bool CheckClaer();
	void MapInit();
	


private:
};

