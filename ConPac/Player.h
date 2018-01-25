#pragma once
enum DIRECTION
{
	UP = 75,
	DOWN = 77,
	RIGHT = 80,
	LEFT = 72
};

struct Player
{
	int x, y;
	DIRECTION dir;

	Player()
	{
		x = 0;
		y = 0;
		dir = RIGHT;
	}

	void Input()
	{
		char input = 0;
		if (_kbhit())//키 눌렀는지 체크
		{
			input = _getch();//어떤키가 눌렀는지 체크

			dir = (DIRECTION)input;
		}
	}

	void Move()
	{
		switch (dir)
		{
		case UP:
			y--;
			if (y < 0)
				y = 0;
			break;
		case DOWN:
			y++;
			if (y > MAPSIZE - 1)
				y = MAPSIZE - 1;
			break;
		case RIGHT:
			x++;
			if (x > MAPSIZE - 1)
				x = MAPSIZE - 1;
			break;
		case LEFT:
			x--;
			if (x < 0)
				x = 0;
			break;
		default:
			break;
		}
	}
};