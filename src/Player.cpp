#include "Player.h"
#include "TowerA.h"

Player::Player(string name, int gold)
{
    this->name = name;
    this->gold = gold;
    this->health = 100;
}
int Player::Gold() const
{
    return this->gold;
}
int Player::Health() const
{
    return this->health;
}
string Player::Name() const
{
	return this->name;
}
vector <Tower*> Player::Towers() const
{
    return this->towers;
}
bool Player::setTower(PlayGround & playground, Tower * tower)
{
    if(this->gold < tower->Cost()) ///< You can set the tower if you don't have enough gold.
        return false;
    else
    {
        this->towers.push_back(tower);
        this->gold -= tower->Cost();
        playground.update(tower->X(), tower->Y(), tower->Name());
        return true;
    }
}
bool Player::sellTower(PlayGround & playground, Tower * tower)
{
    for(int i = 0; i < (int)this->towers.size(); i++)
    {
        if((*towers[i]) == (*tower))
            this->towers.erase(towers.begin() + i);
    }
    this->gold += (tower->Cost() * 0.7);
    playground.update(tower->X(), tower->Y(), ' ');
    return true;
}
void Player::updateFire(int a, int b)
{
    for(int i = 0; i < (int)this->towers.size(); i++)
    {
        if(towers[i]->Name() == 'A')
            (dynamic_cast<TowerA*>(towers[i]))->updateFire(a);
        else
            (dynamic_cast<TowerB*>(towers[i]))->updateBomb(b);
    }
}
void Player::addGold(int a)
{
    this->gold += a;
}
void Player::minusHealth(int a)
{
    this->health -= a;
}
