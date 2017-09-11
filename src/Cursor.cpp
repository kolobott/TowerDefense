#include "Cursor.h"

Cursor::Cursor(int width, int length)
{
    this->widthBorder = width;
    this->lengthBorder = length;
    this->x = 0;
    this->y = 0;
}
void Cursor::gotoxy(int x, int y)
{
    cout<<"\033["<<y+1<<";"<<x+1<<"H"; /**< move cursor to x, y*/
    this->x = x;
    this->y = y;
}
void Cursor::moveUp()
{
    if(y - 1 < 0)
        gotoxy(x, y);
    else
    {
        y--;
        gotoxy(x, y);
    }
}
void Cursor::moveDown()
{
    if(y + 1 > lengthBorder-1)
        gotoxy(x, y);
    else
    {
        y++;
        gotoxy(x, y);
    }
}
void Cursor::moveLeft()
{
    if(x - 1 < 0)
        gotoxy(x, y);
    else
    {
        x--;
        gotoxy(x, y);
    }
}
void Cursor::moveRigth()
{
    if(x + 1 > widthBorder-1)
        gotoxy(x, y);
    else
    {
        x++;
        gotoxy(x, y);
    }
}
void Cursor::goBack()
{
    x--;
    x++;
    gotoxy(x, y);
}
int Cursor::X() const
{
    return this->x;
}
int Cursor::Y() const
{
    return this->y;
}
