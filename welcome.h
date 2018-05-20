#ifndef WELCOME_H
#define WELCOME_H
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <fstream>
#include <SFML/Audio.hpp>

extern long long Coin;
extern long long Record;
extern bool newRecord;

bool Welcome(sf::RenderWindow &app);
#endif // !WELCOME_H

