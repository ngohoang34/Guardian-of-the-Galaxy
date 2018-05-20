#include "run.h"

bool run(sf::RenderWindow &app)
{
replay:
	if (Welcome(app) == 0) return 1;

	sf::SoundBuffer Bcoin;
	Bcoin.loadFromFile("sound/coin.ogg");
	sf::Sound _coin;
	_coin.setBuffer(Bcoin);
	_coin.setVolume(50);

	sf::SoundBuffer Bex;
	Bex.loadFromFile("sound/ex.ogg");
	sf::Sound _ex;
	_ex.setBuffer(Bex);
	_ex.setVolume(50);

	sf::SoundBuffer Bexship;
	Bexship.loadFromFile("sound/exship.ogg");
	sf::Sound _exship;
	_exship.setBuffer(Bexship);
	_exship.setVolume(500);

	sf::SoundBuffer Bshoot;
	Bshoot.loadFromFile("sound/shoot.ogg");
	sf::Sound _shoot;
	_shoot.setBuffer(Bshoot);
	_shoot.setVolume(50);

	sf::Music _gameplay;
	_gameplay.openFromFile("sound/gameplay.ogg");
	_gameplay.setLoop(true);

	sf::SoundBuffer Bin;
	Bin.loadFromFile("sound/in.ogg");
	sf::Sound _in;
	_in.setBuffer(Bin);


	GameOver = 0;
	score = 0;
	_time = 0;
	weapon = 50;

	app.setFramerateLimit(60);


playAgain: _fly_alive = true;
	_in.play();
	_gameplay.play();
	GameOver = 0;
	sf::Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15;
	t1.loadFromFile("images/spaceship1.png");
	t2.loadFromFile("images/background.jpg");
	t3.loadFromFile("images/explosions/type_C.png");
	t4.loadFromFile("images/coin.png");
	t5.loadFromFile("images/fire_blue.png");
	t6.loadFromFile("images/rock_small.png");
	t7.loadFromFile("images/explosions/type_B.png");
	t8.loadFromFile("images/fire_red.png");
	t9.loadFromFile("images/fire_light_blue.png");
	t10.loadFromFile("images/fire.png");
	t11.loadFromFile("images/rock.png");
	t12.loadFromFile("images/explosions/type_coin.png");
	t13.loadFromFile("images/light1.png");
	t14.loadFromFile("images/light2.png");
	t15.loadFromFile("images/light3.png");


	t1.setSmooth(true);
	t2.setSmooth(true);

	sf::Sprite background(t2);

	Animation sExplosion(t3, 0, 0, 256, 256, 48, 0.5);
	Animation sCoin(t4, 0, 0, 85, 64, 16, 0.5);
	Animation L1(t13, 0, 0, 256, 256, 1, 0.5);
	Animation L2(t14, 0, 0, 256, 256, 1, 0.5);
	Animation L3(t15, 0, 0, 256, 256, 1, 0.5);
	Animation sRock(t11, 0, 0, 64, 64, 16, 0.2);
	Animation sRock_small(t6, 0, 0, 64, 64, 16, 0.2);
	Animation sBullets(t8, 0, 0, 32, 64, 16, 0.8);
	Animation sBulletx(t9, 0, 0, 32, 64, 16, 0.8);
	Animation sBulletxx(t10, 0, 0, 32, 64, 16, 0.8);
	Animation sBullet(t5, 0, 0, 32, 64, 16, 0.8);
	Animation sPlayer(t1, 80, 0, 80, 80, 1, 0);
	Animation sPlayer_go(t1, 80, 80, 80, 80, 1, 0);
	Animation sExplosion_ship(t7, 0, 0, 192, 192, 64, 0.5);
	Animation sExplosion_coin(t12, 0, 0, 64, 64, 48, 2);


	std::list<Entity*> entities;


	player *p = new player();
	p->settings(sPlayer, W / 2, H / 2, 0, 20);
	entities.push_back(p);
	sf::Font font;
	font.loadFromFile("Font/manteka.ttf");
	sf::Text sScore, sRecord, sWeapon, ssCoin;
	sScore.setFont(font);
	sScore.setCharacterSize(25);
	sScore.setPosition(15, 55);
	sWeapon.setFont(font);
	sWeapon.setCharacterSize(25);
	sWeapon.setPosition(1020, 15);
	ssCoin.setFont(font);
	ssCoin.setCharacterSize(25);
	ssCoin.setPosition(1020, 55);
	sRecord.setFont(font);
	sRecord.setCharacterSize(25);
	sRecord.setPosition(15, 15);
	std::string Scorex;
	std::string Recordx;
	std::string Weaponx;
	std::string Coinx;
	/////main loop/////
	while (app.isOpen())
	{

		sf::Event event;
		while (app.pollEvent(event))
		{
			if (rand() % 7 == 0) weapon++;
			_time += 0.07;
			score += 0.07;
			if (int(score) > Record)
			{
				Record = int(score);
				newRecord = 1;
			}

			if (event.type == sf::Event::Closed)
				app.close();

			if (event.type == sf::Event::KeyPressed)
				if (event.key.code == sf::Keyboard::Space && weapon)
				{
					_shoot.play();
					if (score > 20) weapon--;
					if (score >= 60 && rand() % 30 == 0) weapon++;
					bullet *b = new bullet();
					if (score >= 60) b->settings(sBullets, p->x, p->y, p->angle, 10);
					else if (score >= 30 && score < 60) b->settings(sBulletxx, p->x, p->y, p->angle, 10);
					else if (score > 20 && score < 30) b->settings(sBullet, p->x, p->y, p->angle, 10);
					else b->settings(sBulletx, p->x, p->y, p->angle, 10);
					entities.push_back(b);
				}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) p->angle += 3;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  p->angle -= 3;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) p->thrust = true;
		else p->thrust = false;



		for (auto a : entities)
			for (auto b : entities)
			{
				if (a->name == "asteroid" && b->name == "bullet")
					if (isCollide(a, b))
					{

						_ex.play();

						a->life = false;
						b->life = false;
						if (score >= 60) score++;
						score += 0.3;
						if (int(score) > Record)
						{
							Record = int(score);
							newRecord = 1;
						}

						Entity *e = new Entity();
						e->settings(sExplosion, a->x, a->y);
						e->name = "explosion";
						entities.push_back(e);


						for (int i = 0; i < 2; i++)
						{
							if (a->R == 15 || score >= 40) continue;
							Entity *e = new asteroid();
							e->settings(sRock_small, a->x, a->y, rand() % 360, 15);
							entities.push_back(e);
						}

					}

				if (a->name == "player" && b->name == "coin")
					if (isCollide(a, b))
					{
						_coin.play();

						b->life = false;
						Coin += 10;

						Entity *e = new Entity();
						e->settings(sExplosion_coin, b->x, b->y);
						e->name = "explosion";
						entities.push_back(e);


					}

				if (a->name == "player" && b->name == "asteroid")
					if (isCollide(a, b))
					{

						_exship.play();

						_fly_alive = false;
						printf("%d\n", _fly_alive);

						b->life = false;

						Entity *e = new Entity();
						e->settings(sExplosion_ship, a->x, a->y);
						e->name = "explosion";
						entities.push_back(e);

						p->settings(sPlayer, W * 10, H * 10, 0, 20);
						p->dx = 0; p->dy = 0;

						GameOver++;


					}
			}


		if (p->thrust)  p->anim = sPlayer_go;
		else   p->anim = sPlayer;


		for (auto e : entities)
			if (e->name == "explosion")
				if (e->anim.isEnd()) e->life = 0;

		if (rand() % 300 == 0)
		{
			light *a = new light();

			a->settings(L1, rand() % W, rand() % H, rand() % 360, 1);
			entities.push_back(a);
		}

		if (rand() % 300 == 1)
		{
			light *a = new light();

			a->settings(L2, rand() % W, rand() % H, rand() % 360, 1);
			entities.push_back(a);
		}

		if (rand() % 300 == 2)
		{
			light *a = new light();

			a->settings(L3, rand() % W, rand() % H, rand() % 360, 1);
			entities.push_back(a);
		}

		if (rand() % 200 == 0)
		{
			coin * a = new coin();
			a->settings(sCoin, rand() % W, H, rand() % 360, 25);
			entities.push_back(a);
		}
		if (rand() % 200 == 0)
		{
			coin *a = new coin();

			a->settings(sCoin, rand() % W, 0, rand() % 360, 25);
			entities.push_back(a);
		}
		if (rand() % 200 == 0)
		{
			coin *a = new coin();
			a->settings(sCoin, 0, rand() % H, rand() % 360, 25);
			entities.push_back(a);
		}
		if (rand() % 200 == 0)
		{
			coin *a = new coin();

			a->settings(sCoin, W, rand() % H, rand() % 360, 25);
			entities.push_back(a);
		}


		if (_time < 1)
		{
			if (rand() % 150 == 0)
			{
				asteroid *a = new asteroid();
				a->settings(sRock, 0, rand() % H, rand() % 360, 25);
				entities.push_back(a);
			}
		}
		else
		{
			if (_time < 3)
			{
				if (rand() % (150 / int(_time)) == 0)
				{
					asteroid *a = new asteroid();
					a->settings(sRock, 0, rand() % H, rand() % 360, 25);
					entities.push_back(a);
				}
			}
			else
			{
				if (rand() % 50 == 0)
				{
					asteroid *a = new asteroid();
					a->settings(sRock, 0, rand() % H, rand() % 360, 25);
					entities.push_back(a);
				}
			}
		}


		for (auto i = entities.begin(); i != entities.end();)
		{
			Entity *e = *i;
			e->update();
			e->anim.update();
			if (e->life == false) { i = entities.erase(i); delete e; }
			else i++;
		}



		//////draw//////
		app.draw(background);

		for (auto i : entities)
			i->draw(app);
		if (newRecord)
		{
			Recordx = "New record: " + std::to_string(Record);
			sRecord.setString(Recordx);
			app.draw(sRecord);
		}
		else
		{
			Recordx = "High score: " + std::to_string(Record);
			Scorex = "Score: " + std::to_string(int(score));
			sScore.setString(Scorex);
			app.draw(sScore);
			sRecord.setString(Recordx);
			app.draw(sRecord);
		}
		if (score <= 20) Weaponx = "warm up";
		else Weaponx = "weapon: " + std::to_string(weapon);
		sWeapon.setString(Weaponx);
		if (weapon < 10) sWeapon.setFillColor(sf::Color::Red);
		app.draw(sWeapon);

		Coinx = "Coin: " + std::to_string(Coin);
		ssCoin.setString(Coinx);
		app.draw(ssCoin);

		app.display();

		if (GameOver > 130)
		{
			_gameplay.stop();
			if (Endgame(app)) goto playAgain;
			else goto replay;
		}
		if (GameOver) GameOver++;
	}
}