#include "TowerA.h"


TowerA::TowerA(int x, int y, int power, int cost, int speed_fire) : Tower(x, y, 1, 'A'), power(power), cost(cost), speed_fire(speed_fire) {}

int TowerA::Cost() const
{
    return this->cost;
}
int TowerA::Power() const
{
    return this->power;
}
int TowerA::Speed_fire() const
{
    return this->speed_fire;
}
void TowerA::hitEnemy(Enemy & enemy)
{
    speed_fire-=1;
    srand(time(0));
    int krit = rand()%5;
    if(speed_fire == 0)
    {
        if(krit == 4)
            enemy.hitted(power*2);
        else
            enemy.hitted(power);
    }
}

bool TowerA::operator == (TowerA & tower)
{
    return this->x == tower.x && this->y == tower.y && this->power == tower.power && this->cost == tower.cost && this->name == tower.name && this->range == tower.range;
}
void TowerA::updateFire(int a)
{
    if(this->speed_fire == 0)
        this->speed_fire = a;
}

