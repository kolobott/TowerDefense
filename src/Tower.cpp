#include "Tower.h"

Tower::Tower(int x, int y, int range, char name)
{
    this->x = x;
    this->y = y;
    this->range = range;
    this->name = name;
}
char Tower::Name() const
{
    return this->name;
}
int Tower::Range() const
{
    return this->range;
}
int Tower::X() const
{
    return this->x;
}
int Tower::Y() const
{
    return this->y;
}
bool Tower::operator==(Tower & tower) const
{
    return this->x == tower.x && this->y == tower.y && this->range == tower.range && this->name == tower.name;
}
