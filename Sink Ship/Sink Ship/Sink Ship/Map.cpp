#include "Map.h"

Map::Map() {

	m_jumlahKapalEnemy = 5;
	m_jumlahKapalPlayer = 5;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			m_MapPlayer[i][j] = '.';
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			m_MapEnemy[i][j] = '.';
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			m_eMap[i][j] = '.';
		}
	}
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			m_pMap[i][j] = '.';
		}
	}
}

void Map::PlayerGetView() {
	for (int i = 0; i <= size; i++) {
		for (int j = 0; j <= size; j++) {
			if (i != size && j != size) {
				std::cout << m_MapPlayer[i][j] << "  ";
			}
			if (j == size) {
				std::cout << i;
			}
			if (i == size && j != size) {
				std::cout << j << "  ";
			}
		}
		std::cout << std::endl;
	}
}

void Map::EnemyGetView() {
	for (int i = 0; i <= size; i++) {
		for (int j = 0; j <= size; j++) {
			if (i != size && j != size) {
				std::cout << m_MapEnemy[i][j] << "  ";
			}
			if (j == size) {
				std::cout << i;
			}
			if (i == size && j != size) {
				std::cout << j << "  ";
			}
		}
		std::cout << std::endl;
	}
}

void Map::BaseMapPlayerView() {
	for (int i = 0; i <= size; i++) {
		for (int j = 0; j <= size; j++) {
			if (i != size && j != size) {
				std::cout << m_pMap[i][j] << "  ";
			}
			if (j == size) {
				std::cout << i;
			}
			if (i == size && j != size) {
				std::cout << j << "  ";
			}
		}
		std::cout << std::endl;
	}
}

void Map::BaseMapEnemyView() {
	for (int i = 0; i <= size; i++) {
		for (int j = 0; j <= size; j++) {
			if (i != size && j != size) {
				std::cout << m_eMap[i][j] << "  ";
			}
			if (j == size) {
				std::cout << i;
			}
			if (i == size && j != size) {
				std::cout << j << "  ";
			}
		}
		std::cout << std::endl;
	}
}

void Map::EditMapPlayer(int x, int y, char simbol,char p_simbol) {
	m_MapPlayer[x][y] = simbol;
	m_pMap[x][y] = p_simbol;
}

void Map::EditMapEnemy(int x, int y, char simbol,char p_simbol) {
	m_MapEnemy[x][y] = simbol;
	m_eMap[x][y] = p_simbol;
}

int Map::PointToHitEnemy(int xCoord, int yCoord) {
	if (m_MapEnemy[xCoord][yCoord] == 'O' || m_MapEnemy[xCoord][yCoord] == 'X') {
		std::cout << "The area already you hit ! Please choose another area !" << std::endl;
		return 3;
	}
	else {
		if (m_eMap[xCoord][yCoord] == '#') {
			m_jumlahKapalEnemy--;
			std::cout << "HIT !!!" << std::endl;
			EditMapEnemy(xCoord, yCoord, 'O', '.');
			return 1;
		}
		else if (m_eMap[xCoord][yCoord] == '.') {
			std::cout << "MISS !!!" << std::endl;
			EditMapEnemy(xCoord, yCoord, 'X', '.');
			return 2;
		}
	}
}

bool Map::PrecisionShoot() {
	bool isLoop = false;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (m_pMap[i][j] == '#') {
				return PointToHitPlayer(i, j);
			}
		}
	}
	return isLoop;
}

bool Map::PointToHitPlayer(int xCoord, int yCoord) {
	if (m_MapPlayer[xCoord][yCoord] == 'O' || m_MapPlayer[xCoord][yCoord] == 'X') {
		std::cout << "The area already you hit ! Please choose another area !" << std::endl;
		return true;
	}
	else {
		if (m_pMap[xCoord][yCoord] == '#') {
			m_jumlahKapalPlayer--;
			std::cout << "HIT !!!" << std::endl;
			EditMapPlayer(xCoord, yCoord, 'O', '.');
			return false;
		}
		else if (m_pMap[xCoord][yCoord] == '.') {
			std::cout << "MISS !!!" << std::endl;
			EditMapPlayer(xCoord, yCoord, 'X', '.');
			return false;
		}
	}
}


int Map::GetShipPlayer() {
	return m_jumlahKapalPlayer;
}

int Map::GetShipEnemy() {
	return m_jumlahKapalEnemy;
}

bool Map::EditGlobalGeneral(int xCoord, int yCoord, std::string role) {
	if (role == "player") {
		if (m_pMap[xCoord][yCoord] != '#' && xCoord < size && yCoord < size) {
			m_pMap[xCoord][yCoord] = '#';
			return false;
		}
		else {
			BaseMapPlayerView();
			std::cout << "Choose another place !" << std::endl;
			return true;
		}
	}
	else if (role == "enemy") {
		if (m_eMap[xCoord][yCoord] != '#') {
			m_eMap[xCoord][yCoord] = '#';
			return false;
		}
		else {
			EnemyGetView();
			return true;
		}
	}
}

Map::~Map() {
	
}