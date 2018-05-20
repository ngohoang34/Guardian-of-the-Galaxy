#include "endgame.h"

bool Endgame(sf::RenderWindow &app)
{
	sf::Music _endgame;
	_endgame.openFromFile("sound/gameover.ogg");
	_endgame.play();
	_endgame.setLoop(true);

	sf::Texture background_1;
	background_1.loadFromFile("images/gameover.jpg");
	sf::Sprite Background_1(background_1);
	sf::Font font;
	font.loadFromFile("Font/manteka.ttf");
	sf::Text Start, Author, Exit, Intro, Rapid;
	Start.setFont(font);
	Rapid.setFont(font);
	Author.setFont(font);
	Exit.setFont(font);
	Intro.setFont(font);
	Intro.setCharacterSize(25);
	Intro.setPosition(30, 585);
	Intro.setString("not enough coins");
	Start.setString("reborn (200 coins)");
	Rapid.setString("Your spaceship has just crashed");
	Rapid.setCharacterSize(60);
	Start.setCharacterSize(40);
	Exit.setCharacterSize(40);
	Exit.setString("main menu");
	Start.setPosition(415, 670);
	Exit.setPosition(505, 570);
	Rapid.setPosition(45, 280);
	while (true)
	{
		sf::Event event;
		while (app.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				app.close();
				return 0;
			}
		}
		srand(time(NULL));
		switch (rand() % 2)
		{
		case 0: Rapid.setFillColor(sf::Color::Red); break;
		case 1: Rapid.setFillColor(sf::Color::White); break;
		}
		app.clear();
		app.draw(Background_1);
		float x = sf::Mouse::getPosition(app).x;
		float y = sf::Mouse::getPosition(app).y;
		int xx = sf::Mouse::getPosition(app).x;
		int yx = sf::Mouse::getPosition(app).y;
		if ((x >= 415) && (x <= 815) && (y >= 670) && (y <= 710))
		{
			Start.setFillColor(sf::Color::Green);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				if (Coin >= 200)
				{
					Coin -= 200;
					return 1;
				}
		}
		else Start.setFillColor(sf::Color::White);

		if ((x >= 505) && (x <= 730) && (y >= 570) && (y <= 610))
		{
			Exit.setFillColor(sf::Color::Green);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				return 0;
			}

		}
		else Exit.setFillColor(sf::Color::White);

		sf::Text sScore, sRecord, ssCoin;
		sScore.setFont(font);
		sScore.setCharacterSize(25);
		sScore.setPosition(520, 390);
		ssCoin.setFont(font);
		ssCoin.setCharacterSize(25);
		ssCoin.setPosition(480, 430);
		std::string Scorex;
		std::string Coinx;
		Scorex = "your score: " + std::to_string(int(score));
		sScore.setString(Scorex);
		Coinx = "You earned " + std::to_string(Coin) + " coin";
		ssCoin.setString(Coinx);

		app.draw(ssCoin);
		app.draw(sScore);
		app.draw(Rapid);
		if (Coin >= 200) app.draw(Start);
		app.draw(Exit);
		app.display();

	}
}