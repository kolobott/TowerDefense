/**
 * @file TowerB.h 
 * @brief This class is a derivate from the class Tower.
 * @author Dmytro Molokoiedov
 * @bugs No known bugs.
 */
#ifndef TOWERB_H_INCLUDED
#define TOWERB_H_INCLUDED

#include "Tower.h"

class TowerB: public Tower
{
private:
    int power; ///< power of thr tower
    int cost, bomb; ///< cost and amount of bombs of the tower
public:
    virtual ~TowerB() {}
    /**
     * @brief Constructor that initialize the tower
     * @param x, y, power, cost, speed_fire
     */
    TowerB(int x, int y, int power, int cost, int bomb);
    /**
     * @brief Getter of the parameter cost
     * @return int
     */
    int Cost() const;
    /**
     * @brief Getter of the parameter power
     * @return int
     */
    int Power() const;
    /**
     * @brief Getter of the parameter bomb
     * @return int
     */
    int Bomb() const;
    /**
     * @brief Method that updates amount of bombs
     * @param a
     * @return void
     */
    void updateBomb(int a);
    /**
     * @brief Operator == for the towers
     * @param tower
     * @return bool
     */
    virtual bool operator == (TowerB & tower);
    /**
     * @brief Method that hits enemy
     * @param enemy
     * @return void
     */
    virtual void hitEnemy(Enemy & enemy);
};



#endif // TOWERB_H_INCLUDED
