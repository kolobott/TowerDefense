#include "Game.h"

int Game::calculateGold(int length, int width) const
{
    if ((length*width)/2 < 350)
	return 450;
    return (length*width)/2 + (length*width)/4;
}
int Game::myGetch() const
{
    struct termios oldt,
    newt;
    int ch;
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    ch = getchar();
    /**< read escape-sequences for arrow keys. */
    if(ch == 27)   
    {
	ch = getchar();
	ch = getchar();
	ch -= 69;
    }
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    return ch;
}
void Game::initialize() const
{
    system("clear");
    cout<<"Hello, my dear friend!!!"<<endl;
    cout<<"In a few minutes you will start the game Tower Defense, but now I want to teach you how to play."<<endl;
    cout<<"First of all, you must write your name, length and width of the playground in a file \"Game\"."<<endl;
    cout<<"There are some things on the playground: '#' is a wall, '=<' is start point for enemies,"<<endl;
    cout<<"'>=' is the last point for enemies."<<endl;
    cout<<"Your task is to set towers on the playground so that enemies don't reach the last point '>='."<<endl;
    cout<<"So, you have two types of towers: A and B. Each tower has power, attack range and cost."<<endl;
    cout<<"Tower B fires every move and have a bomb that deals tenfold damage to the enemies every 10 moves. TowerA has only fires."<<endl;
    cout<<"You can move cursor using \u2190 \u2191 \u2192 \u2193 and press Space to set a tower."<<endl;
    cout<<"You will have some gold to set towers. When you are ready, you can press 's' to start the first wave"<<endl;
    cout<<"Enemies in every next wave have more health than in previous one."<<endl;
    cout<<"If you want to look at characteristics of the tower and the rest of information, you can press 'i'."<<endl<<endl<<endl;
    cout<<"Press ENTER to continue."<<endl;
    cin.ignore(cin.rdbuf()->in_avail());
    cin.get();
}
void Game::run()
{
    string name, buffer;
    int length = 0, width = 0, amountWave = 0;
    int powerA, costA, speed_fireA, powerB, costB, bombB; /**< characteristics for the towers. */
    int healthA, healthB, powerEA, powerEB; /**< health and power of the enemies. */
    bool startWave = false;
    bool win = true;

    ifstream file;
    file.open("examples/Game.txt");
    if(!file)
        throw invalid_argument("File \"Game\" doesn't exist or is not readable.");
    getline(file, buffer); ///<read values from the file 
    file>>name;
    getline(file, buffer);
    getline(file, buffer);
    file>>length;
    file>>width;
    file.close();
    if(name.size() == 0)
        throw invalid_argument("Please write the name!!!");
    if(length <= 0 || width <= 0)
        throw invalid_argument("Length and width must be greater than 0.");
    file.open("examples/Game_Private.txt");
    if(!file)
        throw invalid_argument("File \"Game_Private\" doesn't exist or is not readable.");
    getline(file, buffer);  ///< read values from the file
    getline(file, buffer);
    file>>powerA;
    file>>costA;
    file>>speed_fireA;
    getline(file, buffer);
    getline(file, buffer);
    file>>powerB;
    file>>costB;
    file>>bombB;
    getline(file, buffer);
    getline(file, buffer);
    file>>healthA;
    file>>powerEA;
    getline(file, buffer);
    getline(file, buffer);
    file>>healthB;
    file>>powerEB;
    if(powerA <= 0 || costA <= 0 || speed_fireA <= 0 || powerB <=0 || costB <= 0 || bombB <= 0 || healthA <= 0 || powerEA <= 0 || healthB <= 0 || powerEB<=0)
        throw invalid_argument("You cannot change this file. Now you cannot play this Game.");
    file.close();

    PlayGround playground(length, width); ///< Initialize playground

    length = playground.getLength();
    width = playground.getWidth();

    Player player(name, calculateGold(playground.getLength(), playground.getWidth())); ///< Initialize player

    amountWave = (playground.getLength() * playground.getWidth()) / 300 + 1; ///< amount of waves depending on the size of the playground.

    Cursor cursor(width, length); ///< Initialize cursor

    vector<Wave> waves;
    vector<int> wayY;
    vector<int> wayX;
    for (int i = 1; i <= amountWave; i++)
    {
        int a = rand() % 10 + width / 10 + 2;
        int b = rand() % 10 + length / 10 + 2;
        if(player.Gold() <= 450 || playground.getWidth() < 15 || playground.getLength() < 15)
        {
	    Wave wave((a + b) * (i%(amountWave/3+1)+1), healthA + i*400, powerEA , healthB + i*400, powerEB);
	    waves.push_back(wave);
 	}
        else
	{
	    Wave wave((a + b) * (i%4+1), healthA * (3*i), powerEA * i, healthB * (3*i), powerEB * i); ///< Initializa all waves.
            waves.push_back(wave);
	}
    }

    for (int i = 0; i < amountWave; i++)
    {
        waves[i].checkWay(playground.transform(), wayX, wayY);
        char tow;
        system("clear");
	cursor.gotoxy(0, 0);
        cout<<playground<<endl<<endl;
        cout<<"Score: "<<score<<"               Choose type of the tower(A or B): ";
        do
        {
            cin>>tow;
            tow = toupper(tow);
            if(tow == 'B')
                break;
            system("clear");
	    cursor.gotoxy(0, 0);
            cout << playground << endl << endl;
            cout << "Score: " << score << "               Choose type of the tower(A or B): ";
            cin.ignore(256, '\n');
            cin.clear();
        }while(tow != 'A');
        system("clear");
	cursor.gotoxy(0, 0);
        cout << playground << endl << endl;
        cout << "Score: " << score << "               Choose type of the tower(A or B): " << tow << endl << endl;
        cout << "Gold: " << player.Gold() << "               Press c to change type of the tower    "<<endl<<endl;
        cout << "Player: "<<player.Name() << "               Amount of waves: "<<amountWave<<endl<<endl;
        cout << "Press i to see the characteristics of towers and enemies.		Press q to exit."<<endl<<endl;
	cout << "Press s to start the wave.";
        cursor.gotoxy(4, 1);
        while(1)
        {
            int c;
            c = 0;
            switch(c=myGetch())
            {
                case KEY_UP:
                    cursor.moveUp();
                    break;
                case KEY_DOWN:
                    cursor.moveDown();
                    break;
                case KEY_LEFT:
                    cursor.moveLeft();
                    break;
                case KEY_RIGHT:
                    cursor.moveRigth();
                    break;
                case START_WAVE:
                    system("clear");
		    cursor.gotoxy(0, 0);
                    cout << playground << endl << endl;
                    cout << "Score: " << score << "               Choose type of the tower(A or B): " << tow << endl << endl;
                    cout << "Gold: " << player.Gold() << "               Press c to change type of the tower    ";
                    cout << "Player: "<<player.Name() << "               Amount of waves: "<<amountWave<<endl<<endl;
                    cout << "Press i to see the characteristics of towers and enemies.		Press q to exit."<<endl<<endl;
		    cout << "Press s to start the wave.";
                    cursor.gotoxy(cursor.X(), cursor.Y());
                    startWave = true;
                    break;
		case EXIT:
		    char answer;
		    do
		    {
			system("clear");
		    	cursor.gotoxy(0, 0);
			cout<<"Are you sure? (y, n)"<<endl;
		        cin>>answer;
		    	answer = tolower(answer);
		    	if(answer == 'y')
		        {
			    system("clear");
		            return;
			}
		    	cursor.gotoxy(0, 0);
		    	cin.ignore(256, '\n');
		    	cin.clear();
		    }while(answer != 'n');
		    system("clear");
                    cout << playground << endl << endl;
                    cout << "Score: " << score << "               Choose type of the tower(A or B): " << tow << endl << endl;
                    cout << "Gold: " << player.Gold() << "               Press c to change type of the tower    "<<endl<<endl;
                    cout << "Player: "<<player.Name() << "               Amount of waves: "<<amountWave<<endl<<endl;
                    cout << "Press i to see the characteristics of towers and enemies.		Press q to exit."<<endl<<endl;
		    cout << "Press s to start the wave.";
		    cursor.gotoxy(0, 0);
		    break;
                case CHANGE:
                    system("clear");
                    cout << playground << endl << endl;
                    cout << "Score: " << score << "               Choose type of the tower(A or B): " << (tow == 'A'? tow = 'B' : tow = 'A') << endl << endl;
                    cout << "Gold: " << player.Gold() << "               Press c to change type of the tower    "<<endl<<endl;
                    cout << "Player: "<<player.Name() << "               Amount of waves: "<<amountWave<<endl<<endl;
                    cout << "Press i to see the characteristics of towers and enemies.		Press q to exit."<<endl<<endl;
		    cout << "Press s to start the wave.";
                    cursor.gotoxy(cursor.X(), cursor.Y());
                    break;
                case INFORMATION:
                    system("clear");
		    cursor.gotoxy(0, 0);
                    cout<<"TowerA: power = "<<powerA<<", cost = "<<costA<<", tower fires every "<<speed_fireA<<" move(s)."<<endl;
                    cout<<"TowerB: power = "<<powerB<<", cost = "<<costB<<", bomb explodes every "<<bombB<<" moves."<<endl;
                    cout<<"EnemyA: health = "<<waves[i].Vector()[0]->Health()<<endl;
                    cout<<"EnemyB: health = "<<waves[i].Vector()[1]->Health()<<endl<<endl;
                    cout<<"Press Enter to continue the game.";
		    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
                    system("clear");
		    cursor.gotoxy(0, 0);
                    cout << playground << endl << endl;
                    cout << "Score: " << score << "               Choose type of the tower(A or B): " << tow << endl << endl;
                    cout << "Gold: " << player.Gold() << "               Press c to change type of the tower    "<<endl<<endl;
                    cout << "Player: "<<player.Name() << "               Amount of waves: "<<amountWave<<endl<<endl;
                    cout << "Press i to see the characteristics of towers and enemies.		Press q to exit."<<endl<<endl;
		    cout << "Press s to start the wave.";
                    cursor.gotoxy(cursor.X(), cursor.Y());
		    break;
                case SPACE:
                    int x = cursor.Y();
                    int y = cursor.X();
                    if(playground.isFree(x, y))
                    {
                        playground.update(x, y, tow);
                        if (!waves[i].checkWay(playground.transform(), wayX, wayY))
                        {
                            playground.update(x, y, ' ');
                            continue;
                        }
                        else
                        {
                            playground.update(x, y, ' ');
                            if(tow == 'A')
                            {
                                Tower * tower = new TowerA(x, y, powerA, costA, speed_fireA);
                                if(player.setTower(playground, tower))
                                {
                                    cout<<'A';
                                    cursor.gotoxy(0, length + 4);
                                    cout << "Gold: " << player.Gold() << "               Press c to change type of the tower    "<<endl<<endl;
                                    cout << "Player: "<<player.Name() << "               Amount of waves: "<<amountWave<<endl<<endl;
                                    cout << "Press i to see the characteristics of towers and enemies.		Press q to exit."<<endl<<endl;
				    cout << "Press s to start the wave.";
                                    cursor.gotoxy(y, x);
                                    continue;
                                }
                                continue;
                            }
                            else if(tow == 'B')
                            {
                                Tower * tower = new TowerB(x, y, powerB, costB, bombB);
                                if(player.setTower(playground, tower))
                                {
                                    cout<<'B';
                                    cursor.gotoxy(0, length + 4);
                                    cout << "Gold: " << player.Gold() << "               Press c to change type of the tower    "<<endl<<endl;
                                    cout << "Player: "<<player.Name() << "               Amount of waves: "<<amountWave<<endl<<endl;
                                    cout << "Press i to see the characteristics of towers and enemies.		Press q to exit."<<endl<<endl;
				    cout << "Press s to start the wave.";
                                    cursor.gotoxy(y, x);
                                    continue;
                                }
                                continue;
                            }

                        }
                    }
                    else if (playground.Vector()[x][y] == 3 || playground.Vector()[x][y] == 4)
                    {
                        if(tow == 'A')
                        {
                            Tower * tower = new TowerA(x, y, powerA, costA, speed_fireA);
                            if(player.sellTower(playground, tower))
                            {
                                cout<<' ';
                                cursor.gotoxy(0, length + 4);
                                cout << "Gold: " << player.Gold() << "               Press c to change type of the tower    "<<endl<<endl;
                                cout << "Player: " << player.Name() << "               Amount of waves: "<<amountWave<<endl<<endl;
                                cout << "Press i to see the characteristics of towers and enemies.		Press q to exit."<<endl<<endl;
				cout << "Press s to start the wave.";
                                cursor.gotoxy(y, x);
                                continue;
                            }
                            continue;
                        }
                        else if(tow == 'B')
                        {
                            Tower * tower = new TowerB(x, y, powerB, costB, bombB);
                            if(player.sellTower(playground, tower))
                            {
                                cout<<' ';
                                cursor.gotoxy(0, length + 4);
                                cout << "Gold: " << player.Gold() << "               Press c to change type of the tower    "<<endl<<endl;
                                cout << "Player: "<<player.Name() << "               Amount of waves: "<<amountWave<<endl<<endl;
                                cout << "Press i to see the characteristics of towers and enemies.		Press q to exit."<<endl<<endl;
				cout << "Press s to start the wave.";
                                cursor.gotoxy(y, x);
                                continue;
                            }
                            continue;
                        }

                    }
                    break;
            }
            if(startWave)
            {
                startWave = false;
                break;
            }
        }
        int endX = wayX[wayX.size()-1];
        int endY = wayY[wayY.size()-1];
        int countDead = 0;
        for(int j = 0; j < (int)waves[i].Vector().size(); j++)
        {
            wayY.push_back(0);
            wayX.push_back(0);
        }
        system("clear");
	cursor.gotoxy(0, 0);
        cout<<playground<<endl<<endl;
        cout << "Score: " << score << "               Choose type of the tower(A or B): " << tow << endl << endl;
        cout << "Gold: " << player.Gold() << "               Press c to change type of the tower    "<<endl<<endl;
        cout << "Player: "<<player.Name() << "               Amount of waves: "<<amountWave;
	int g = i;
        for(int j = 0; j < (int)wayY.size(); j++)
        {
	    cursor.gotoxy(0, 0);
            waves[i].Move(wayY[j], wayX[j], cursor);
            waves[i].print(cursor);
            player.updateFire(speed_fireA, bombB);
            for(int k = 0; k < (int)player.Towers().size(); k++)
            {
                for(int y = 0; y < (int)waves[i].Vector().size(); y++)
                {
                    if((abs(player.Towers()[k]->X()-waves[i].Vector()[y]->X()) + abs(player.Towers()[k]->Y()-waves[i].Vector()[y]->Y())) <= player.Towers()[k]->Range())
                    {
                        if(waves[i].Vector()[y]->isAlive())
                        {
			    if(g == 0)
			    {
                                player.Towers()[k]->hitEnemy(*(waves[i].Vector()[y]));
			    }
			    else
			        g--;
                            if(waves[i].Vector()[y]->Health() <= 0)
                            {
                                waves[i].Vector()[y]->Dead();
                                countDead++;
                                if(waves[i].Vector()[y]->Name() == '%')
                                {
                                    score += 30 + 2*i;
                                    player.addGold(4*(i+1));
                                }
                                else
                                {
                                    score += 60 + 2*i;
                                    player.addGold(8*(i+1));
                                }
                            }
                        }
                    }
                }
            }
            if(countDead == (int)waves[i].Vector().size()-2)
            {
                usleep(500*1000);
                break;
            }
            usleep(200*1000);
            for(int k = 0; k < (int)waves[i].Vector().size(); k++)
            {
                if(waves[i].Vector()[k]->isAlive() && waves[i].Vector()[k]->X() == endY && waves[i].Vector()[k]->Y() == endX)
                {
                    if(waves[i].Vector()[k]->Name() == '%')
                        player.minusHealth(2);
                    else
                        player.minusHealth(4);
                    break;
                }
            }
            if(player.Health() <= 0)
            {
                win = false;
                break;
            }
            cursor.gotoxy(0, length+2);
            cout<<"Score: "<<score<<"                       Player health: "<<player.Health()<<"             "<<endl<<endl;
            cout << "Gold: " << player.Gold() << "               Press c to change type of the tower    "<<endl<<endl;
            cout << "Player: "<<player.Name() << "               Wave "<<i+1<<"               "<<endl;
	    cursor.gotoxy(0, 0);
        }
        if(!win)
	{
	   cout<<flush;
           break;
	}
    }
    cout<<flush;
    if(!win)
    {
        system("clear");
	cursor.gotoxy(0, 0);
        for(int i = 0; i < length; i++)
        {
            cout<<"Game over"<<endl;
        }
    }
    else
    {
        system("clear");
	cursor.gotoxy(0, 0);
        for(int i = 0; i < length; i++)
        {
            cout<<"You win"<<endl;
        }
	cout<<"You win"<<endl;
        cout<<"Score is "<<score<<endl;
	ofstream file;
	file.open("examples/Scores.txt", ofstream::app);
	file<<playground<<player.Name()<<": "<<score<<endl;
	file<<"-----------------------------------------------------"<<endl<<endl;
	file.close();
    }
}







