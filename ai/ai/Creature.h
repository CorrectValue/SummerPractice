#include <SFML/Graphics.hpp>
using namespace sf; //������������ ���� sf ������

class Creature 
{
public:
	float hp, x, y, w, h, dx, dy, speed;
	int dir;
	Image image;//���� �����������
	Texture texture;//���� ��������
	Sprite sprite;//���� ������
	Creature();
	Creature(int, int, int);
	void update(float);
};