#include <string>
#include "EnemyB.h"

EnemyB::EnemyB(int health, int power) : Enemy('@'), health(health), power(power), alive(true), color("Green") {}

void EnemyB::Move(int x, int y)
{
    this->x = x;
    this->y = y;
}
bool EnemyB::isAlive() const
{
    return this->alive;
}
void EnemyB::Dead()
{
    this->alive = false;
    this->health = 0;
    this->name = ' ';
}
void EnemyB::hitted(int health)
{
    this->health -= health;
}
int EnemyB::Health() const
{
    return this->health;
}
int EnemyB::Power() const
{
    return this->power;
}
string EnemyB::Color() const
{
    return this->color;
}
