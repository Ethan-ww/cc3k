#include "player.h"
#include "character.h"

Player::Player() {}

Player::Player(int hp, int atk, int def) : Character(hp, atk, def, false){}

Player::~Player() {}

