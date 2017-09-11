/**
 * @file TowerA.h 
 * @brief This class is a derivate from the class Tower.
 * @author Dmytro Molokoiedov
 * @bugs No known bugs.
 */
#ifndef TOWERA_H_INCLUDED
#define TOWERA_H_INCLUDED

#include <cstdlib>
#include "Tower.h"

class TowerA: public Tower
{
private:
    int power; ///< power of the tower
    int cost, speed_fire; ///< cost and speed of fire of the tower
public:
    virtual ~TowerA() {}
    /**
     * @brief Constructor that initialize the tower
     * @param x, y, power, cost, speed_fire
     */
    TowerA(int x, int y, int power, int cost, int speed_fire);
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
     * @brief Getter of the parameter speed_fire
     * @return int
     */
    int Speed_fire() const;
    /**
     * @brief Method that updates speed of fire
     * @param a
     * @return void
     */
    void updateFire(int a);
    /**
     * @brief Operator == for the towers
     * @param tower
     * @return bool
     */
    virtual bool operator == (TowerA & tower);
    /**
     * @brief Method that hits enemy
     * @param enemy
     * @return void
     */
    virtual void hitEnemy(Enemy & enemy);
};

#endif // TOWERA_H_INCLUDED
