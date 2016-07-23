#ifndef CREATURE
#define CREATURE
#include <SFML/Graphics.hpp>
#include "map.h"

using namespace sf; //пространство имен sf блеать

class Creature 
{
public:
	float hp, x, y, w, h, dx, dy, speed;
	int dir;
	int money;
	Image image;//сфмл изображение
	Texture texture;//сфмл текстура
	Sprite sprite;//сфмл спрайт
	Creature();
	Creature(int, int, int);
	void update(float);
	void mapInteraction();
	void takeDamage(float);
};
#endif