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
	//� ����������� �� ����������� �������� direction ������� ��������� � �������
	//1 - �����
	//0 - ����
	//2 - �����
	//3 - ������
	switch (dir)
	{
	case 0:
		//����
		sprite.setTextureRect(IntRect(0, 0, 16, 16));//��������� ����� �� ����������� ��������
		dy = speed;
		dx = 0;
		break;
	case 1:
		//�����
		sprite.setTextureRect(IntRect(0, 17, 16, 16));
		dy = -speed;
		dx = 0;
		break;
	case 2:
		//�����
		sprite.setTextureRect(IntRect(17, 17, 16, 16));
		dx = -speed;
		dy = 0;
		break;
	case 3:
		//������
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

