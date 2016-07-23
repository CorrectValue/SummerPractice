#include "Player.h"
#include "map.h"
#include <Windows.h>
void Player::spawnCoin()
{
	int X, Y;
	bool success = false;
	do{
		X = rand() % HEIGHT_MAP;
		Y = rand() % WIDTH_MAP;
		if (TileMap[X][Y] == ' ')
		{
			TileMap[X][Y] = 'c';
			success = true;
		}
	} while (!success);
	Sleep(100);
}

void Player::spawnMedkit()
{
	int X, Y;
	bool success = false;
	do{
		X = rand() % HEIGHT_MAP;
		Y = rand() % WIDTH_MAP;
		if (TileMap[X][Y] == ' ')
		{
			TileMap[X][Y] = 'h';
			success = true;
		}
	} while (!success);
	Sleep(100);
}

void Player::whistle()
{

}