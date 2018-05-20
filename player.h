#ifndef PLAYER_H
#define PLAYER_H
#include "Entity.h"

extern bool _fly_alive;

class player : public Entity
{
	public:
	bool thrust;

	player();
	void update();
};


#endif // !

