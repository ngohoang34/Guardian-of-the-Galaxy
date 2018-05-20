#include "player.h"

player::player()
	{
		name = "player";
	}

	void player::update()
	{
		if (thrust)
		{
			dx += cos(angle*DEGTORAD)*0.2;
			dy += sin(angle*DEGTORAD)*0.2;
		}
		else
		{
			dx *= 0.97;
			dy *= 0.97;
		}

		int maxSpeed = 5;
		float speed = sqrt(dx*dx + dy*dy);
		if (speed > maxSpeed)
		{
			dx *= maxSpeed / speed;
			dy *= maxSpeed / speed;
		}

		x += dx;
		y += dy;

		if (_fly_alive)
		{
			if (x > W) x = 0; if (x < 0) x = W;
			if (y > H) y = 0; if (y < 0) y = H;

		}
	}
