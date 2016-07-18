#include <SFML/Graphics.hpp>
using namespace sf; //пространство имен sf блеать

class Creature 
{
public:
	float hp, x, y, w, h, dx, dy, speed;
	int dir;
	Image image;//сфмл изображение
	Texture texture;//сфмл текстура
	Sprite sprite;//сфмл спрайт
	Creature();
	Creature(int, int, int);
	void update(float);
};