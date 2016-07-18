#include <SFML/Graphics.hpp>
#include "Creature.h"
#include <conio.h>
#include "map.h"
using namespace sf; //пространство имен sf блеать

int main()
{
	Image mapImg;//изображение карты
	mapImg.loadFromFile("Images/grass-tileset.png");
	Texture map;//текстура карты
	map.loadFromImage(mapImg);
	Sprite mapSpr;
	mapSpr.setTexture(map);

	RenderWindow window(sf::VideoMode(640, 480), "GETTING STARTED");
	//float CurrentFrame = 0;//хранит текущий кадр
	Clock clock;

	Creature plr;
	plr.sprite.setPosition(plr.x, plr.y);//начальные координаты появления спрайта
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
		

		window.clear();
		for (int i = 0; i < HEIGHT_MAP; i++)
		{
			for (int j = 0; j < WIDTH_MAP; j++)
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
				mapSpr.setPosition(j*16, i*16);
				window.draw(mapSpr);
			}
		}
		window.draw(plr.sprite);//рисуем спрайт объекта p класса player
		window.display();
	}

	return 0;
}