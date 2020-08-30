#pragma once
#include "Map.h"


class Enemy {
public:
	Enemy();
	~Enemy();

	void Attack(Map& map);
	void SetShip(Map& map);
	void SetDifficult(double p_chanceMiss);
	double NRand(double fMin, double fMax);
	

	std::string GetName();

private:
	std::string m_nameEnemy;

	double m_chanceMiss;

};