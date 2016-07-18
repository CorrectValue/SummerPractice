#include "Creature.h"

Creature::Creature()
{
	dir = 0;
	image.loadFromFile("Images/purple-sprite.png");//
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	x = 32;
	y = 32;
	speed = 0.1;
	w = 16;
	h = 16;
	sprite.setTextureRect(IntRect(0, 0, w, h));
}

Creature::Creature(int X, int Y, int SPEED)
{
	x = X;
	y = Y;
	speed = SPEED;
	dir = 0;
	image.loadFromFile("Images/purple-sprite.png");//
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	w = 16;
	h = 16;
	sprite.setTextureRect(IntRect(0, 0, w, h));
}

void Creature::update(float time)
{
	//в зависимости от полученного значения direction двигает персонажа в стороны
	//1 - вверх
	//0 - вниз
	//2 - влево
	//3 - вправо
	switch (dir)
	{
	case 0:
		//вниз
		sprite.setTextureRect(IntRect(0, 0, 16, 16));//повернуть перса по направлению движения
		dy = speed;
		dx = 0;
		break;
	case 1:
		//вверх
		sprite.setTextureRect(IntRect(0, 17, 16, 16));
		dy = -speed;
		dx = 0;
		break;
	case 2:
		//влево
		sprite.setTextureRect(IntRect(17, 17, 16, 16));
		dx = -speed;
		dy = 0;
		break;
	case 3:
		//вправо
		sprite.setTextureRect(IntRect(17, 0, 16, 16));
		dx = speed; 
		dy = 0;
		break;
	default:
		break;
	}
	x += dx*time;
	y += dy*time;
	sprite.setPosition(x, y);

}

