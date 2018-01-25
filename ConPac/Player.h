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
		if (_kbhit())//Ű �������� üũ
		{
			input = _getch();//�Ű�� �������� üũ

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