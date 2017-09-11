/**
 * @file Tower.h 
 * @brief An abstract class that derivates two classes: TowerA and TowerB.
 * @author Dmytro Molokoiedov
 * @bugs No known bugs.
 */
#ifndef TOWER_H_INCLUDED
#define TOWER_H_INCLUDED

#include <iostream>
#include <vector>
#include "Enemy.h"

using namespace std;

class Tower
{
protected:
    int x; ///< x coordinate of the tower
    int y; ///< y coordinate of the tower
    int range; ///< range of the tower
    char name; ///< name of the tower (A or B)
public:
    /** 
     * @brief Constructor that sets x, y, range and the name of the tower.
     * @param x, y, range, name
     */
    Tower(int x, int y, int range, char name);
    virtual ~Tower() {}
    /**
     * @brief Getter of the parameter x
     * @return int
     */
    virtual int X() const;
    /**
     * @brief Getter of the parameter y
     * @return int
     */
    virtual int Y() const;
    /**
     * @brief Getter of the parameter name
     * @return char
     */
    virtual char Name() const;
    /**
     * @brief Getter of the parameter range
     * @return int
     */
    virtual int Range() const;
    /**
     * @brief Abstract getter of the parameter cost
     * @return int
     */
    virtual int Cost() const = 0;
    /**
     * @brief Abstract method that hits enemy
     * @param enemy
     * @return void
     */
    virtual void hitEnemy(Enemy & enemy) = 0;
    /**
     * @brief Operator == for the towers
     * @param tower
     * @return bool
     */
    virtual bool operator ==(Tower & tower) const;
};


#endif // TOWER_H_INCLUDED
