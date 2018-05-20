#include "welcome.h"

bool Welcome(sf::RenderWindow &app)
{
	sf::SoundBuffer Bin;
	Bin.loadFromFile("sound/in.ogg");
	sf::Sound _in;
	_in.setBuffer(Bin);
	if (Coin != -1) _in.play();
	sf::Music _welcome;
	_welcome.openFromFile("sound/welcome.ogg");
	_welcome.play();
	_welcome.setLoop(true);

	std::fstream f;
	f.open("Record.data", std::ios::in);
	long long tg, TG;
	f >> TG >> tg;
	f.close();
	if (Coin == -1) Coin = TG;
	f.open("Record.data", std::ios::out);
	if (newRecord) tg = Record;
	Record = tg;
	f << Coin << " " << Record;
	f.close();
	newRecord = 0;

	sf::Texture background_1;
	background_1.loadFromFile("Image/background_1.png");
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
	Intro.setString("HOW TO PLAY\nPress <UP> to move\nPress <LEFT> to turn left\npress <RIGHT> to turn right\nPress <SPACE> to shoot");
	Start.setString("Start");
	Rapid.setString("Guardian of the Galaxy");
	Rapid.setCharacterSize(70);
	Start.setCharacterSize(40);
	Exit.setCharacterSize(40);
	Exit.setString("Exit");
	Start.setPosition(545, 200);
	Exit.setPosition(555, 270);
	Rapid.setPosition(180, 80);
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
		switch (rand() % 5)
		{
		case 0: Rapid.setFillColor(sf::Color::Cyan); break;
		case 1: Rapid.setFillColor(sf::Color::Red); break;
		case 2: Rapid.setFillColor(sf::Color::Magenta); break;
		case 3: Rapid.setFillColor(sf::Color::Green); break;
		case 4: Rapid.setFillColor(sf::Color::White); break;
		}
		app.clear();
		app.draw(Background_1);
		float x = sf::Mouse::getPosition(app).x;
		float y = sf::Mouse::getPosition(app).y;
		if ((x >= 545) && (x <= 665) && (y >= 200) && (y <= 240))
		{
			Start.setFillColor(sf::Color::Green);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				return 1;
		}
		else Start.setFillColor(sf::Color::White);

		if ((x >= 555) && (x <= 645) && (y >= 270) && (y <= 310))
		{

			Exit.setFillColor(sf::Color::Green);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				_in.play();
				return 0;
			}
		}
		else Exit.setFillColor(sf::Color::White);

		app.draw(Intro);
		app.draw(Rapid);
		app.draw(Start);
		app.draw(Exit);
		app.display();
	}
}