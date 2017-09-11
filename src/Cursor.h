/**
 * @file Cursor.h
 * @brief This class alows to move cursor in terminal.
 * @author Dmytro Molokoiedov
 * @bugs No known bugs.
 */
#ifndef CURSOR_H_INCLUDED
#define CURSOR_H_INCLUDED

#include <iostream>
#include <stdio.h>
#include <unistd.h>

using namespace std;

class Cursor
{
private:
    int x, y; /**< x, y coordinates of cursor*/
    int widthBorder;
    int lengthBorder;
public:
    /**
     * @brief Constructor that  creates cursor and sets borders
     * @param width, length
     */
    Cursor(int width, int length);
    /**
     * @brief Method that sets the coordinates of the cursor.
     * @param x, y
     * @return void
     */
    void gotoxy(int x, int y);
    /**
     * @brief Method that moves cursor up.
     * @return void
     */
    void moveUp();
    /**
     * @brief Method that moves cursor down.
     * @return void
     */
    void moveDown();
    /**
     * @brief Method that moves cursor left.
     * @return void
     */
    void moveLeft();
    /**
     * @brief Method that moves cursor right.
     * @return void
     */
    void moveRigth();
    /**
     * @brief Method that moves cursor back to the previous coordinates.
     * @return void
     */
    void goBack();
    /**
     * @brief Getter of coordinate x
     * @return int
     */
    int X() const;
    /**
     * @brief Getter of coordinate x
     * @return int
     */
    int Y() const;
};

#endif // CURSOR_H_INCLUDED
