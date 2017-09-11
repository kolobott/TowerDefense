#include <string>
#include "Enemy.h"

Enemy::Enemy(char name)
{
    x = 0;
    y = 0;
    this->name = name;
}
int Enemy::X() const
{
    return this->x;
}
int Enemy::Y() const
{
    return this->y;
}
char Enemy::Name() const
{
    return this->name;
}

