#include <windows.h>
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
#include "run.h"

bool _fly_alive = true;
long long Record;
long long Coin = -1;
bool newRecord = 0;
double score = 0;
int GameOver = 0;
double _time = 0;
long long weapon = 50;

int main()
{
	srand(time(0));
	sf::RenderWindow app(sf::VideoMode(W, H), "Guardian of the Galaxy", Style::None);
	run(app);
	return 0;
}
