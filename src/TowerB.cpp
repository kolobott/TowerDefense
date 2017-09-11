#include "TowerB.h"

TowerB::TowerB(int x, int y, int power, int cost, int bomb) : Tower(x, y, 2, 'B'), power(power), cost(cost), bomb(bomb) {}

int TowerB::Cost() const
{
    return this->cost;
}
int TowerB::Power() const
{
    return this->power;
}
int TowerB::Bomb() const
{
    return this->bomb;
}
void TowerB::hitEnemy(Enemy & enemy)
{
    bomb-=1;
    if(this->bomb == 0)
        enemy.hitted(power*10);
    else
        enemy.hitted(power);
}
bool TowerB::operator == (TowerB & tower)
{
    return this->x == tower.x && this->y == tower.y && this->power == tower.power && this->cost == tower.cost && this->name == tower.name && this->range == tower.range;
}
void TowerB::updateBomb(int a)
{
    if(this->bomb == 0)
        this->bomb = a;
}
