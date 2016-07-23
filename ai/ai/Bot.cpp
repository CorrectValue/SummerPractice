#include "Bot.h"
#include <Windows.h>
#include <ctime>

Bot::Bot()
{
	dir = 0;
	image.loadFromFile("Images/deep-blue.png");//
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	goal = 0;
	x = 550;
	hearsWhistle = false;
	y = 32;
	found = false;
	radius = 3;
	speed = 0.1;
	hp = 80;
	destX = -1;
	destY = -1;
	w = 16;
	h = 16;
	sprite.setTextureRect(IntRect(0, 0, w, h));
}

void Bot::wander()
{
	dir = rand() % 4;
}

void Bot::goalPlanner()
{
	//��������, ��� ������ ����
	if (hearsWhistle)
	{
		goal = 3;//����� ������
	}
	else if (hp < 100)
	{
		goal = 1;//����� �������
	}
	else
	{
		goal = 2;//���� ��� ������� �������, ���� �������
	}
}

void Bot::actionPlanner(float X, float Y)
{
	if (goal == 3)
		searchForPlayer(X, Y);
	if (goal == 1)
		searchForObject('h');
	if (goal == 2)
		searchForObject('c');
}

void Bot::moveTo(int X, int Y)
{
	//������������� � ���������� X, Y
	if (X < int(x/16))
		dir = 2; //��������� �����
	if (X > int(x/16))
		dir = 3; //��������� ������
	if (abs(X - int(x/16)) < 2)
	{
		//���� �� � ���������� �����, ������������� �� Y
		if (Y < int(y/16))
			dir = 1; // ��������� �����
		if (Y > int(y/16))
			dir = 0; //��������� ����
	}
	//����� �����������, ���� �� ���-�� ��������
	//if (dir == 0 && TileMap[int(y / 16) + 1][int(x / 16)] != ' ')
	//	dir = 3;//������
	//if (dir == 1 && TileMap[int(y / 16) - 1][int(x / 16)] != ' ')
	//	dir = 2;//�����
	//if (dir == 2 && TileMap[int(y / 16)][int(x / 16) - 1] != ' ')
	//	dir = 0;//����
	//if (dir == 3 && TileMap[int(y / 16)][int(x / 16) + 1] != ' ')
	//	dir = 1;//�����
}

void Bot::searchForObject(char c)
{
	int dirX, dirY;
	if (!found)
	{
		if (destX == -1)
		{
			srand(time(NULL));
			destX = rand() % 39 + 1;//��������� ���������� �� � � Y
			srand(time(NULL));
			destY = rand() % 29 + 1; 
			/*if (dirX % 2 != 0)
			{
				if (x / 16 - 2 > 0)
					destX = x / 16 - 2;
				else
					destX = x / 16 + 2;
			}
			else
			{
				if (x / 16 + 2 < 40)
					destX = x / 16 + 2;
				else
					destX = x / 16 - 2;
			}
			if (dirY % 2 == 0)
			{
				if (y / 16 - 2 > 0)
					destY = y / 16 - 2;
				else
					destY = y / 16 + 2;
			}
			else
			{
				if (y / 16 + 2 < 30)
					destY = y / 16 + 2;
				else
					destY = y / 16 - 2;
			}*/
		}
		moveTo(destX, destY);
		if (abs(int(x / 16) - destX) < 2 && abs(int(y / 16) - destY) < 2)
		{
			//������ � ������ �����, �������� ����� ����������
			destX = -1;
			destY = -1;
		}
		for (int i = int(x / 16) - 2; i < int(x / 16) + 2 && i > -1; i++)
		{
			for (int j = int(y / 16) - 2; j < int(y / 16) + 2 && j > -1; j++)
			{
				if (TileMap[j][i] == c)
				{
					found = true;
					destX = i;
					destY = j;
				}
			}
		}
		
	}
	if (found)
	{
		moveTo(destX, destY);
		if (abs(x / 16 - destX) < 1 && abs(y / 16 - destY) < 1)
		{
			//������ � ������ �����, �������� ����� ����������
			destX = -1;
			destY = -1;
			//���������� found ���� ��������, �.�. ����� ��� ������
			found = false;
			//�������, ��� �������� ����, ��������� � ��������� �������� (goal = 0)
			goal = 0;
		}
	}
}

void Bot::AI(float X, float Y)
{
	//����� ��������, ������������ ��������� ����
	goalPlanner(); //������ �������� - ����������, ��� ��������� ���� ����� �� �����
	actionPlanner(X, Y); //����������� ��������, ����������� ��� ���������� ����
}

void Bot::searchForPlayer(float X, float Y)
{
	//���������� ���� � ����������� � ������
	moveTo(X / 16, Y / 16);
}