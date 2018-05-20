#include "light.h"

	light::light()
	{
		if (rand() % 2) dx = 5;
		else dx = -5;
		if (rand() % 2) dy = 5;
		else dy = -5;
		name = "light";
	}

	void light::update()
	{
		x += dx - (rand() % 5);
		y += dy - (rand() % 5);

		if (x > W) this->life = 0;  if (x < 0) this->life = 0;
		if (y > H) this->life = 0;  if (y < 0) this->life = 0;
	}

