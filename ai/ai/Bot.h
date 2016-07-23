#ifndef BOT
#define BOT
#include "Creature.h"
class Bot : public Creature
{
public:
	int goal; //����������, ���������� �� ��, ��� ����� ������ ��� � ���������� ������
	//0 - ��������
	//1 - ����� �������
	//2 - ����� �����
	//3 - ����� ������
	bool hearsWhistle; //����������, ���������� �� ��,��� ��� ������� ����� ������
	bool inRange;
	bool inView;
	int radius;//������ ������
	int destX, destY;
	bool found;//�������� �� ��, ����� ��� ��, ��� ��� �����, ��� ���
	Bot();
	void wander();
	void goalPlanner();
	void actionPlanner(float, float);
	void moveTo(int X, int Y);
	void searchForObject(char);
	void searchForPlayer(float, float);
	void AI(float, float);
};
#endif