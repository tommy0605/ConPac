#pragma once
#include "Map.h"

class PMan;
class Gost;
class GMA
{
public:
	GMA();
	~GMA();
	void GetGxy(Gost* g);
	void GetPxy(PMan* pac);
	void MoveA();

private:
	int gx;
	int gy;
	int px;
	int py;

};

