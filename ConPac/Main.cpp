#include "Map.h"
#include "Gost.h"
#include "PManager.h"
#include "PMan.h"

void main()
{
	Gost gost[4];
	PMan pac;
	Map mapc;
	PManager manager(&mapc, &pac, gost);
	
	manager.UI();




	
	ofstream score;
	score.open("highscore.txt", ios::out);
	score << manager.highscore << endl;
	score.close();
}