#ifndef PLAYER
#define PLAYER
#include "Creature.h"
class Player : public Creature
{
public:
	void spawnMedkit();
	void spawnCoin();
	void Player::whistle();
};
#endif