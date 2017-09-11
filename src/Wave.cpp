#include "Wave.h"

Wave::Wave(int a, int healthA, int powerEA, int healthB, int powerEB)
{
    srand(time(0));
    this->wave.push_back(new EnemyA(healthA, powerEA));
    this->wave.push_back(new EnemyB(healthB, powerEB));
    for(int i = 2; i < a; i++)
    {
        int b = rand()%2;
        if(b == 0)
            this->wave.push_back(new EnemyA(healthA, powerEA));
        else
            this->wave.push_back(new EnemyB(healthB, powerEB));
    }
}
vector<Enemy*> Wave::Vector() const
{
    return this->wave;
}
bool Wave::checkWay(vector< vector<int> > a1, vector<int> & px, vector<int> & py) const
{
    vector< vector<int> > a(a1);
    int dx[4] = { 1, 0, -1, 0 }; ///< x coordinates of the nearest square
    int dy[4] = { 0, 1, 0, -1 }; ///< y coordinates of the nearest square
    int d, x, y, k;
    bool stop;

    if (a[a.size() / 2][3] == -1 || a[a.size() / 2][a[0].size() - 3] == -1) return false; ///< checks if the start or last point are not free.

    d = 0;
    a[a.size() / 2][3] = 0;
    do 
    {
	stop = true;
	for (y = 0; y < (int)a.size(); ++y)
	    for (x = 0; x < (int)a[0].size(); ++x)
		if (a[y][x] == d)
		{
		    for (k = 0; k < 4; ++k)
	     	    {
			int iy = y + dy[k], ix = x + dx[k];
			if (iy >= 0 && iy < (int)a.size() && ix >= 0 && ix < (int)a[0].size() && a[iy][ix] == -2)
			{
			    stop = false;
			    a[iy][ix] = d + 1;
			}
		    }
		}
	d++;
    } while (!stop &&  a[a.size() / 2][a[0].size() - 3] == -2);

    if (a[a.size() / 2][a[0].size() - 3] == -2) return false;

    int len = a[a.size() / 2][a[0].size() - 3];
    x = a[0].size() - 3;
    y = a.size() / 2;
    d = len;
    px.resize(d + 1, 0);
    py.resize(d + 1, 0);
    while (d > 0)
    {
	px[d] = x;
	py[d] = y;
	d--;
	for (k = 0; k < 4; ++k)
	{
	    int iy = y + dy[k], ix = x + dx[k];
	    if (iy >= 0 && iy < (int)a.size() && ix >= 0 && ix < (int)a[0].size() && a[iy][ix] == d)
	    {
		x = x + dx[k];
		y = y + dy[k];
		break;
	    }
	}
    }
    px[0] = 3;
    py[0] = a.size() / 2;
    return true;
}
void Wave::Move(int x, int y, Cursor & cursor)
{
    int ax = wave[0]->X(), ay = wave[0]->Y();
    int ax_prev = wave[0]->X(), ay_prev = wave[0]->Y();
    wave[0]->Move(x, y);
    for(int i = 1; i < (int)wave.size()-2; i++)
    {
      ax_prev = wave[i]->X(), ay_prev = wave[i]->Y();
      wave[i]->Move(ax, ay);

      ax = ax_prev; ay = ay_prev;
    }
    cursor.gotoxy(ay, ax);
    cout<<' ';
    cursor.gotoxy(0, 0);
}
void Wave::print(Cursor & cursor) const
{
    for(int i = 0; i < (int)wave.size(); i++)
    {
        cursor.gotoxy(wave[i]->Y(), wave[i]->X());
	if(wave[i]->X() == 0 && wave[i]->Y() == 0)
	    cout<<'#';
        else
	    cout<<wave[i]->Name();
    }
}

