#include "Player.h"


Player::Player() {
	m_namePlayer = "";
}


void Player::Attack(Map& map) {
	int pointX, pointY, n_casual;
	do {
		map.EnemyGetView();
		std::cout << "Choose the Coordinat to Attack ! : (Y,X) : ";
		std::cin >> pointX >> pointY;
		n_casual = map.PointToHitEnemy(pointX, pointY);
	} while (n_casual == 3);
}

void Player::SetName(std::string p_name) {
	m_namePlayer = p_name;
}

std::string Player::GetName() {
	return m_namePlayer;
}

void Player::SetShip(Map& map) {
	int n_count = map.GetShipPlayer();
	int xCoord, yCoord;
	for (int i = 0; i < map.GetShipPlayer(); i++) {
		map.BaseMapPlayerView();
		std::cout << GetName() << " place the ship ! " << std::endl;
		std::cout << "Ship left : " << n_count - i << std::endl << std::endl;
		do {
			std::cout << "Enter Ship Location : (Y,X) : ";
			std::cin >> xCoord >> yCoord;
			system("cls");
		} while (map.EditGlobalGeneral(xCoord, yCoord, "player"));
	}
}

Player::~Player() {

}