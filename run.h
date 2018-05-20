#ifndef RUN_H
#define RUN_H
#include <SFML/Graphics.hpp>
#include <time.h>
#include <list>
#include <windows.h>
#include <stdio.h>
#include <fstream>
#include <SFML/Audio.hpp>
#include "Animation.h"
#include "Entity.h"
#include "isCollide.h"
#include "light.h"
#include "coin.h"
#include "asteroid.h"
#include "bullet.h"
#include "player.h"
#include "welcome.h"
#include "endgame.h"

extern bool _fly_alive;
extern long long Record;
extern long long Coin;
extern bool newRecord;
extern double score;
extern int GameOver;
extern double _time;
extern long long weapon;

bool run(sf::RenderWindow &app);

#endif // !RUN_H

