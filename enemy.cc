#include "character.h"
#include "enemy.h"

Enemy::Enemy() {}

Enemy::Enemy(int hp, int atk, int def) : Character(hp, atk, def, true) {}

Enemy::~Enemy() {}

