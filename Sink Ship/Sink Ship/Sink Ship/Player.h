#pragma once
#include "Map.h"


class Player {
public:
	Player();
	~Player();

	void Attack(Map& map);
	void SetShip(Map& map);
	void SetName(std::string p_name);
	std::string GetName();

private:
	std::string m_namePlayer;
};