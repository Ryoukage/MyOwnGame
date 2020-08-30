#include "Enemy.h"
#include "Player.h"
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

int Random(int low, int high) {
	return rand() % high + low;
}

void GenerateRandomTurn(Player& player,Enemy& enemy,std::string& turn) {
	for (int i = 0; i < Random(10, 15); i++) {
		std::cout << "Sedang memilih giliran pertama secara acak !!!" << std::endl;
		int cd = Random(1, 100);
		if (cd % 2 == 0) {
			std::cout << player.GetName() << std::endl;
			turn = player.GetName();
		}
		else {
			std::cout << enemy.GetName() << std::endl;
			turn = enemy.GetName();
		}
		Sleep((150 + i * 5) + 250);
		system("cls");
	}
}

void ChangeTurn(std::string& turn, Player& player, Enemy& enemy) {
	if (turn == player.GetName()) {
		turn = enemy.GetName();
	}
	else if (turn == enemy.GetName()) {
		turn = player.GetName();
	}
}

void GamePlay(Player& player, Enemy& enemy, Map& map, std::string turn) {
	if (turn == player.GetName()) {
		std::cout << player.GetName() << "'s Turn !" << "||" << "\t" << "Enemy Ship Left : " << map.GetShipEnemy() << std::endl;
		player.Attack(map);
	}
	else if (turn == enemy.GetName()) {
		std::cout << enemy.GetName() << "'s Turn !" << "||" << "\t" << "Player Ship Left : " << map.GetShipPlayer() << std::endl;
		enemy.Attack(map);
	}
}

void ChooseDifficulty(Enemy& enemy) {
	int x;
	std::cout << "1.Easy\n2.Medium\n3.Hard\n4.Extreme\nChoose your difficult :";
	std::cin >> x;
	switch (x)
	{
	case 1:
		enemy.SetDifficult(8.5);
		break;
	case 2:
		enemy.SetDifficult(5.5);
		break;
	case 3:
		enemy.SetDifficult(2.5);
	default:
	case 4:
		enemy.SetDifficult(0.75);
		break;
	}
}

int main() {
	srand(static_cast<unsigned int>(time(NULL)));
	std::string name;
	std::string turn = "";

	Player player;
	Enemy enemy;
	Map map;

	

	std::cout << "Masukkan Nama Karaktermu : ";
	std::cin >> name;


	ChooseDifficulty(enemy);

	player.SetName(name);
	player.SetShip(map);
	enemy.SetShip(map);

	GenerateRandomTurn(player, enemy, turn);

	std::cout << turn << " get first turn !!!" << std::endl;
	Sleep(1000);

	for (int i = 5; i >= 0; i--) {
		std::cout << "Game Start In ";
		std::cout << i;
		Sleep(1000);
		system("cls");

	}
	std::cout << std::endl;

	while (map.GetShipPlayer() > 0 && map.GetShipEnemy() > 0) {
		GamePlay(player, enemy, map, turn);
		ChangeTurn(turn, player, enemy);
		Sleep(1500);
		system("cls"); 
	}

	if (map.GetShipPlayer() == 0) {
		std::cout << enemy.GetName() << " Is Winner !!!" << std::endl;
	}
	else if (map.GetShipEnemy() == 0) {
		std::cout << player.GetName() << " Is Winner !!!" << std::endl;
	}

	

	


}

