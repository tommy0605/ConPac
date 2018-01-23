#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#define WIDETH 28
#define HEIGHT 31

class Map
{
public:
	Map();
	~Map();
	void DrawMap();

private:
	int mapi[HEIGHT][WIDETH];
};

