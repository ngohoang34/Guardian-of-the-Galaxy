#include "coin.h"

coin::coin()
	{
		if (rand() % 2) dx = 1;
		else dx = -1;
		if (rand() % 2) dy = 1;
		else dy = -1;
		name = "coin";
	}

	void coin:: update()
	{
		x += dx - (rand() % 2);
		y += dy - (rand() % 2);

		if (x > W) this->life = 0;  if (x < 0) this->life = 0;
		if (y > H) this->life = 0;  if (y < 0) this->life = 0;
	}
