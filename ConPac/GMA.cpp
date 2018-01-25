#include "GMA.h"
#include "PMan.h"
#include "Gost.h"



GMA::GMA()
{
	gx = 0;
	gy = 0;
	px = 0;
	py = 0;
}


GMA::~GMA()
{
}

void GMA::GetGxy(Gost * g)
{
	gx = g->x;
	gy = g->y;
}

void GMA::GetPxy(PMan * pac)
{
	px = pac->x;
	py = pac->y;
}


void GMA::MoveA()
{
	

	//TODO::고스트 이동 알고리즘 구현
}
