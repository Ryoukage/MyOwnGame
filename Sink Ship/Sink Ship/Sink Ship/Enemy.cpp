#include "Enemy.h"
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

Enemy::Enemy() {
	m_nameEnemy = "Kawaiii-Chan";
	m_chanceMiss = 0;
}

double Enemy::NRand(double pMin,double pMax){
	double f = (double)rand() / RAND_MAX;
	return pMin + f * (pMax - pMin);
}


std::string Enemy::GetName() {
	return m_nameEnemy;
}

void Enemy::Attack(Map& map) {
	int pointX, pointY;
	double shootPrecision;
	bool isLoop = false;

	map.PlayerGetView();
	do {
		std::cout << "Thinking";
		for (int i = 0; i < NRand(3, 5); i++) {
			std::cout << " .";
			Sleep(NRand(500,750));
		}
		std::cout << std::endl;
		pointX = NRand(0.00, static_cast<double>(size));
		pointY = NRand(0.00, static_cast<double>(size));

		
		shootPrecision = NRand(0.00, 10.00);
		if (shootPrecision > m_chanceMiss) {
			isLoop = map.PrecisionShoot();
			break;
		}
		else {
			isLoop = map.PointToHitPlayer(pointX, pointY);
		}
	} while (isLoop);

}


void Enemy::SetShip(Map& map) {
	int n_count = map.GetShipEnemy();
	int xCoord, yCoord;
	for (int i = 0; i < map.GetShipEnemy(); i++) {
		map.EnemyGetView();
		std::cout << GetName() << " Place the ship !" << std::endl;
		std::cout << "Ship left : " << n_count - i << std::endl << std::endl;
		do {
			std::cout << "Thinking ";
			for (int j = 0; j < NRand(1, 5); j++) {
				std::cout << ". ";
				Sleep(NRand(500, 750));
			}
			xCoord = NRand(0, size);
			yCoord = NRand(0, size);
			system("cls");
		} while (map.EditGlobalGeneral(xCoord, yCoord, "enemy"));
	}
}

void Enemy::SetDifficult(double p_chanceMiss) {
	m_chanceMiss = p_chanceMiss;
}

Enemy::~Enemy() {

}