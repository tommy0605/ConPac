#include "PMan.h"



PMan::PMan()
{
	x = 1;
	y = 1;
	life = 3;
	doa = true;
	mapnum = 5;

}


PMan::~PMan()
{
}

void PMan::Move()
{
	char key;
	cin >> key;

	



}

bool PMan::CheckMap(Map * map)
{
	//TODO::맵에서 이동가능한지 체크
	return false;
}

bool PMan::CheckGost(Gost * g)
{
	return false;
}
