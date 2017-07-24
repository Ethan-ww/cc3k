#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "character.h"

class Player : public Character {
public:
	Player();
	Player(int hp, int atk, int def);
	~Player();

};

#endif
