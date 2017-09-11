#include "PlayGround.h"

PlayGround::PlayGround(vector< vector<int> > help)
{
	this->ground.resize(help.size(), vector<int>(help[0].size()));
	this->ground = help;
	this->width = ground[0].size();
	this->length = ground.size();
}
PlayGround::PlayGround(int length, int width)
{
        if(length < 9)
            length = 9;
        if(length > 33)
            length = 33;
        this->length = length%2 == 0? length+1 : length;
        if(width < 36)
            width = 36;
        if(width > 111)
            width = 111;
        if(width < this->length * 2)
            this->width = this->length * 2;
        else
            this->width = width%2 == 0? width+1 : width;
        ground.resize(this->length, vector<int>(this->width));
        for(int i = 0; i < this->width; i++)
        {
            ground[0][i] = 7;
            ground[this->length-1][i] = 7;
        }
        for(int i = 0; i < this->length; i++)
        {
            ground[i][0] = 7;
            ground[i][this->width-1] = 7;
        }
        ground[this->length/2][1] = 1;
        ground[this->length/2][this->width-2] = 1;
        ground[this->length/2][2] = 2;
        ground[this->length/2][this->width-1] = 2;
        srand(time(0));
        int w, l;
        for(int i = 0; i < (this->width*this->length)/9; i++)
        {
            l = rand()%(this->length-3) + 1;
            w = rand()%(this->width-8) + 4;
            ground[l][w] = 7;
        }
}
ostream & operator<<(ostream & os, const PlayGround & a)
{
    for(int i = 0; i < a.length; i++)
    {
        for(int j = 0; j < a.width; j++)
        {
            int en = a.ground[i][j];
            if(en == 0)
                os<<' ';
            else if(en == 1)
                os<<'=';
            else if(en == 2)
                os<<'<';
            else if(en == 3)
                os<<'A';
            else if(en == 4)
                os<<'B';
            else if(en == 5)
                os<<'%';
            else if(en == 6)
                os<<'@';
	    else if (en == 7)
		os << '#';
        }
        os<<endl;
    }
    return os;
}
void PlayGround::update(int i, int j, char tower)
{
    if (tower == 'A')
        ground[i][j] = 3;
    else if (tower == 'B')
	ground[i][j] = 4;
    else if (tower == ' ')
	ground[i][j] = 0;

}
int PlayGround::getLength() const
{
    return this->length;
}
int PlayGround::getWidth() const
{
    return this->width;
}
bool PlayGround::isFree(int x, int y) const
{
    return ground[x][y] == 0;
}
vector< vector<int> > PlayGround::Vector() const
{
    return this->ground;
}
vector< vector<int> > PlayGround::transform() const
{
    vector< vector<int> > help(this->ground);
    for (int i = 0; i < (int)help.size(); i++)
    {
	for (int j = 0; j < (int)help[i].size(); j++)
	{
	    if (help[i][j] != 0)
		help[i][j] = -1;
            else
		help[i][j] = -2;
	}
    }
    return help;
}
