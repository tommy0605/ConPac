#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#define WIDETH 28
#define HEIGHT 31
class PMan;
class Gost;
class Map
{
public:
	int mapi[HEIGHT][WIDETH];
	Map();
	~Map();
	void DrawMap();
	void InputPac(PMan* pac);
	void InputGost(Gost* g);
	


private:
};

