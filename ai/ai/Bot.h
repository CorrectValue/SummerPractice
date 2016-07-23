#ifndef BOT
#define BOT
#include "Creature.h"
class Bot : public Creature
{
public:
	int goal; //переменная, отвечающая за то, что будет делать бот в глобальном смысле
	//0 - безделье
	//1 - поиск аптечки
	//2 - поиск монет
	//3 - поиск игрока
	bool hearsWhistle; //переменная, отвечающая за то,что бот услышал свист игрока
	bool inRange;
	bool inView;
	int radius;//радиус обзора
	int destX, destY;
	bool found;//отвечает за то, нашел бот то, что ему нужно, или нет
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