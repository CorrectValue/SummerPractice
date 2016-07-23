#ifndef CREATURE
#define CREATURE
#include <SFML/Graphics.hpp>
#include "map.h"

using namespace sf; //������������ ���� sf ������

class Creature 
{
public:
	float hp, x, y, w, h, dx, dy, speed;
	int dir;
	int money;
	Image image;//���� �����������
	Texture texture;//���� ��������
	Sprite sprite;//���� ������
	Creature();
	Creature(int, int, int);
	void update(float);
	void mapInteraction();
	void takeDamage(float);
};
#endif