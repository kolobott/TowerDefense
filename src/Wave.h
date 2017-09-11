/**
 * @file Tower.h 
 * @brief An abstract class that derivates two classes: TowerA and TowerB.
 * @author Dmytro Molokoiedov
 * @bugs No known bugs.
 */
#ifndef WAVE_H_INCLUDED
#define WAVE_H_INCLUDED

#include "EnemyA.h"
#include "EnemyB.h"
#include "Cursor.h"
#include <cstdlib>
#include <vector>




class Wave
{
private:
    vector<Enemy*> wave; ///< vector of enemies that are in the wave
public:
    /**
     * @brief Constructor that creates wave. Amount of enemies - a.
     * @param a, healthA, powerEA, healthB, powerEB
     */
    Wave(int a, int healthA, int powerEA, int healthB, int powerEB);
    /**
     * @brief Method that checks if way exists to the end of the playground
     * @param a, px, py
     * @return bool
     */
    bool checkWay(vector< vector<int> > a, vector<int> & px, vector<int> & py) const; 
    /**
     * @brief Getter for the parameter wave
     * @return vector<Enemy*>
     */
    vector<Enemy*> Vector() const;
    /** 
     * @brief Method that moves the wave to x, y
     * @param x, y
     * @return void
     */
    void Move(int x, int y, Cursor & cursor);
    /** 
     * @brief Method that prints the wave on the playground
     * @param cursor
     * @return void
     */
    void print(Cursor & cursor) const;
};

#endif // WAVE_H_INCLUDED
