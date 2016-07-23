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
	hp = 100;
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
	hp = 100;
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
	if (x+dx*time < 640)
		x += dx*time;
	if (y+dy*time < 480)
		y += dy*time;
	mapInteraction();
	sprite.setPosition(x, y);
}

void Creature::mapInteraction()
{
	for (int i = y / 16; i < (y + h) / 16; i++)
	{
		for (int j = x / 16; j < (x + w) / 16; j++)
		{
			if (TileMap[i][j] == 'i')
			{
				if (dx > 0)
					x = j * 16 - w;
				if (dx < 0)
					x = j * 16 + 16;
			}
			if (TileMap[i][j] == 's' || TileMap[i][j] == 'w')
			{
				if (dx > 0)
					x = j * 16 - w;
				if (dx < 0)
					x = j * 16 + 16;
				if (dy > 0)
					y = i * 16 - h;
				if (dy < 0)
					y = i * 16 + 16;
			}
			if (TileMap[i][j] == '-')
			{
				if (dy > 0)
					y = i * 16 - h;
				if (dy < 0)
					y = i * 16 + 16;
			}
			if (TileMap[i][j] == 'c')
			{
				money++;
				TileMap[i][j] = ' ';
				printf("Creature takes a coin!\n");
			}
			if (TileMap[i][j] == 'h')
			{
				if (hp < 100)
				{
					hp += 30;
					TileMap[i][j] = ' ';
				}
			}
			printf("%d %d\n", i, j);
		}
	}
}

void Creature::takeDamage(float dmg)
{
	hp -= 20;
	printf("Creature takes %f damage!\n", dmg);
}
