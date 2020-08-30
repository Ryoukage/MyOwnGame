#pragma once
#include <iostream>
#include <vector>
#include "Const.h"


class Map {
public:

	Map();
	~Map();

	void PlayerGetView();
	void EnemyGetView();
	void BaseMapPlayerView();
	void BaseMapEnemyView();
	void EditMapPlayer(int x, int y, char simbol, char p_simbol);
	void EditMapEnemy(int x, int y, char simbol, char p_simbol);
	bool PrecisionShoot();
	
	bool EditGlobalGeneral(int xCoord, int yCoord, std::string role);
	bool PointToHitPlayer(int x, int y);

	int PointToHitEnemy(int x, int y);
	int GetShipPlayer();
	int GetShipEnemy();




private:
	int m_jumlahKapalPlayer;
	int m_jumlahKapalEnemy;


	char m_MapEnemy[size][size];
	char m_MapPlayer[size][size];
	char m_pMap[size][size];
	char m_eMap[size][size];
};