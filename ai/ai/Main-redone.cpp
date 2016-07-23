//#include "Creature.h"
#include <conio.h>
#include "map.h"
#include "Bot.h"
#include "Player.h"
#include <Windows.h>

using namespace sf;



int main()
{
	Image mapImg;//изображение карты
	mapImg.loadFromFile("Images/grass-tileset.png");
	Texture map;//текстура карты
	map.loadFromImage(mapImg);
	Sprite mapSpr;
	mapSpr.setTexture(map);
	bool botView = false;

	RenderWindow window(sf::VideoMode(640, 480), "GETTING STARTED");
	Clock clock;

	Player plr;
	Bot mob;

	int res; //квадрат радиуса обзора моба

	plr.sprite.setPosition(plr.x, plr.y);//начальные координаты появления спрайта
	mob.sprite.setPosition(mob.x, mob.y);
	while (window.isOpen())
	{

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			plr.dir = 1;
			plr.update(time);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			plr.dir = 0;
			plr.update(time);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			plr.dir = 2;
			plr.update(time);
		}
		else if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			plr.dir = 3;
			plr.update(time);
		}
		else if (Keyboard::isKeyPressed(Keyboard::C))
			plr.spawnCoin();
		else if (Keyboard::isKeyPressed(Keyboard::H))
			plr.spawnMedkit();
		else if (Keyboard::isKeyPressed(Keyboard::V))
		{
			//сменить вид
			if (botView == false)
				botView = true;
			else
				botView = false;
			Sleep(100);
		}
		else if (Keyboard::isKeyPressed(Keyboard::W))
		{
			//игрок издает свист, и бот начинает его искать
			mob.hearsWhistle = true;
		}
		mob.AI(plr.x, plr. y);
		mob.update(time);
		window.clear();
		for (int i = 0; i < HEIGHT_MAP; i++)
		{
			for (int j = 0; j < WIDTH_MAP; j++)
			{
				res = abs((mob.x + 8) / 16 - j)*abs((mob.x + 8) / 16 - j) + abs((mob.y + 8) / 16 - i)*abs((mob.y + 8) / 16 - i);
				if (res <= mob.radius*mob.radius)
					mob.inView = true;
				else
					mob.inView = false;
				if (!botView || (botView && mob.inView))
				{
					if (TileMap[i][j] == '7')
						mapSpr.setTextureRect(IntRect(48, 0, 16, 16));
					if (TileMap[i][j] == ' ')
						mapSpr.setTextureRect(IntRect(0, 0, 16, 16));
					if (TileMap[i][j] == 'w')
						mapSpr.setTextureRect(IntRect(64, 16, 16, 16));
					if (TileMap[i][j] == 's')
						mapSpr.setTextureRect(IntRect(16, 0, 16, 16));
					if (TileMap[i][j] == 'i')
						mapSpr.setTextureRect(IntRect(16, 16, 16, 16));
					if (TileMap[i][j] == '-')
						mapSpr.setTextureRect(IntRect(32, 16, 16, 16));
					if (TileMap[i][j] == 'r')
						mapSpr.setTextureRect(IntRect(32, 0, 16, 16));
					if (TileMap[i][j] == 'L')
						mapSpr.setTextureRect(IntRect(64, 0, 16, 16));
					if (TileMap[i][j] == 'J')
						mapSpr.setTextureRect(IntRect(48, 16, 16, 16));
					if (TileMap[i][j] == 'p')
						mapSpr.setTextureRect(IntRect(0, 16, 16, 16));
					if (TileMap[i][j] == 'c')
						mapSpr.setTextureRect(IntRect(80, 0, 16, 16));
					if (TileMap[i][j] == 'h')
						mapSpr.setTextureRect(IntRect(80, 16, 16, 16));
				}
				else
				{
					mapSpr.setTextureRect(IntRect(96, 0, 16, 16));
				}
				mapSpr.setPosition(j * 16, i * 16);
				window.draw(mapSpr);

			}
		}
		if (!botView || (botView && mob.inView))
			window.draw(plr.sprite);//рисуем спрайт объекта p класса player
		window.draw(mob.sprite);
		window.display();
	}

	return 0;
}