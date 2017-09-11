#include "EnemyA.h"


EnemyA::EnemyA(int health, int power) : Enemy('%'), health(health), power(power), alive(true) {} 

void EnemyA::Move(int x, int y)
{
    this->x = x;
    this->y = y;
}
bool EnemyA::isAlive() const
{
    return this->alive;
}
void EnemyA::Dead()
{
    this->alive = false;
    this->health = 0;
    this->name = ' ';
}
void EnemyA::hitted(int health)
{
    this->health -= health;
}
int EnemyA::Health() const
{
    return this->health;
}
int EnemyA::Power() const
{
    return this->power;
}
