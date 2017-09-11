CXX=g++
CXXFLAGS=-Wall -pedantic -Wno-long-long -O0 -ggdb -std=c++11
LD=g++
LDFLAGS=-Wall -pedantic -Wno-long-long -O0 -ggdb -std=c++11

all: game

game: ./src/main.o ./src/Tower.o ./src/TowerA.o ./src/TowerB.o ./src/Enemy.o ./src/EnemyA.o ./src/EnemyB.o \
	./src/Player.o ./src/PlayGround.o ./src/Wave.o ./src/Cursor.o ./src/Game.o
	$(LD) $(LDFLAGS) ./src/main.o ./src/Tower.o ./src/TowerA.o ./src/TowerB.o ./src/Enemy.o ./src/EnemyA.o ./src/EnemyB.o \
	./src/Player.o ./src/PlayGround.o ./src/Wave.o ./src/Cursor.o ./src/Game.o -o molokdmy

#%.o: 	%.cpp
#	$(CXX) $(CXXFLAGS) -c $< -o $@

doc:
	cd src ; doxygen -g smart_conf.txt; doxygen smart_conf.txt; mv html ../doc

run:
	./molokdmy

clean: 
	rm -f molokdmy *.o; rm -f src/smart_conf.txt; rm -rf doc; rm -rf src/latex; cd src; rm -f *.o

compile: game
	
Game.o: Game.cpp Game.h PlayGround.h Player.h Wave.h Cursor.h
	$(CXX) $(CXXFLAGS) -c Game.cpp -o Game.o

Player.o: Player.cpp Player.h TowerA.h TowerB.h PlayGround.h
	$(CXX) $(CXXFLAGS) -c Player.cpp -o Player.o

Wave.o: Wave.cpp Wave.h EnemyA.h EnemyB.h Cursor.h
	$(CXX) $(CXXFLAGS) -c Wave.cpp -o Wave.o

Tower.o: Tower.cpp Tower.h Enemy.h
	$(CXX) $(CXXFLAGS) -c Tower.cpp -o Tower.o

main.o: main.cpp Game.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

TowerA.o: TowerA.cpp TowerA.h Tower.h
	$(CXX) $(CXXFLAGS) -c TowerA.cpp -o TowerA.o

TowerB.o: TowerB.cpp TowerB.h Tower.h
	$(CXX) $(CXXFLAGS) -c TowerB.cpp -o TowerB.o

Enemy.o: Enemy.cpp Enemy.h
	$(CXX) $(CXXFLAGS) -c Enemy.cpp -o Enemy.o

EnemyA.o: EnemyA.cpp EnemyA.h Enemy.h
	$(CXX) $(CXXFLAGS) -c EnemyA.cpp -o EnemyA.o

EnemyB.o: EnemyB.cpp EnemyB.h Enemy.h
	$(CXX) $(CXXFLAGS) -c EnemyB.cpp -o EnemyB.o

Cursor.o: Cursor.cpp Cursor.h
	$(CXX) $(CXXFLAGS) -c Cursor.cpp -o Cursor.o

PlayGround.o: PlayGround.cpp PlayGround.h
	$(CXX) $(CXXFLAGS) -c PlayGround.cpp -o PlayGround.o
