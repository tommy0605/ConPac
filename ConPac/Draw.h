#pragma once
#include "DoubleBuffering.h"

class Draw
{
private:
	DoubleBuffering* buffer;	

public:
	char* map;
	int size;

	Draw()
	{
		buffer = NULL;
		size = 0;
	}

	void CreateBuffer(int x, int y)
	{
		buffer = new DoubleBuffering(x, y);
		size = (x + 1) * y ;
		map = new char[size];
		//map = {};
	}
	void Print()
	{
		buffer->BufferWrite(0, 0, map);
	}

	void Flipping()
	{
		buffer->BufferFlipping();
	}

	void Clear()
	{
		buffer->ClearBuffer();
	}
};