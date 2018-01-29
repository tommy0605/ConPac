#include "Map.h"
#include "Gost.h"
#include "PManager.h"
#include "PMan.h"
#include "Draw.h"

void main()
{
	Gost gost[4];
	PMan pac;
	Map mapc;
	Draw draw;
	PManager manager(&mapc, &pac, gost, &draw);
	
	manager.UI();




	
	ofstream score;
	score.open("highscore.txt", ios::out);
	score << manager.highscore << endl;
	score.close();
}