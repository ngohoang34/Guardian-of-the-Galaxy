#pragma once

#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Define_Values.h"

using namespace sf;

class Entity
{
public:
	float x, y, dx, dy, R, angle;
	bool life;
	std::string name;
	Animation anim;

	Entity();

	void settings(Animation &a, int X, int Y, float Angle = 0, int radius = 1);

	virtual void update() {};

	void draw(RenderWindow &app);

	virtual ~Entity() {};
};

#endif // !ENTITY_H

