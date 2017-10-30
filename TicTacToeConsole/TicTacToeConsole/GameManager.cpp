#include "GameManager.h"
#include "Console.h"
#include <iostream>

namespace TTT
{
	GameManager::GameManager()
	{
		player = true;
		stateGame = true;
		map = new MapGame();
	}
	int GameManager::MiniMax(int playerr)
 	{
		/*DAT::gotoXY(2, 25);
		map->ShowMapGame();*/
		int move = -1;
		int score = -2;
		int winner = WinGame();
		if (WinGame() == 2)
		{
			winner = 0;
		}
		if (winner != 0) return winner * playerr;
		for (int i = 1; i <= 9; i++)
		{
			if (map->CheckMapGame(i) == true)
			{
				map->SetMapGame(playerr, i);
				int thisScore = -MiniMax(playerr * (-1));
				if (thisScore > score)
				{
					score = thisScore;
					move = i;
				}
				map->SetMapGame(0, i);
			}
			
		}
		if (move == -1) return 0;
		return score;
	}

	GameManager::~GameManager()
	{
		delete map;
	}
	void GameManager::GamePlay()
	{
		int luaChon;
		bool checkWin = false;
		bool checkMapGame = true;
		DAT::gotoXY(2,12);
		if (player == true)
		{
			std::cout << "Luot Choi X:\n Lua Chon o trong (1-9): ";
			do
			{
				std::cin >> luaChon;
				checkMapGame = map->CheckMapGame(luaChon);
				if (checkMapGame == true)
				{
					map->SetMapGame((-1), luaChon);
				}
				if (luaChon < 0 || luaChon >9 || checkMapGame == false)
				{
					std::cout << "\nBan Da Nhap Sai : (1-9) Hoac vi tri da co lua chon : \n";
				}
			} while (luaChon < 0 || luaChon > 9|| checkMapGame == false);
			player = false;
		}
		else
		{
			// Phát triển cho AI ở đây
			int move = -1;
			int score = -2;
			for (int i = 1; i <= 9; i++)
			{
				if (map->CheckMapGame(i) == true)
				{
					map->SetMapGame(1, i);
					int tempScore = -MiniMax(-1);
					map->SetMapGame(0, i);
					if (tempScore > score)
					{
						score = tempScore;
						move = i;
					}
				}
			}
			map->SetMapGame(1, move);
			player = true;
			//=============================================================
			// 2 player
			/*DAT::gotoXY(2, 12);
			std::cout << "Luot Choi O:\n Lua Chon o trong (1-9): ";
			do
			{
				std::cin >> luaChon;
				checkMapGame = map->CheckMapGame(luaChon);
				if (checkMapGame == true)
				{
					map->SetMapGame(1, luaChon);
				}
				if (luaChon < 0 || luaChon >9 || checkMapGame == false)
				{
					std::cout << "\nBan Da Nhap Sai : (1-9) Hoac vi tri da co lua chon : \n";
				}

			} while (luaChon < 0 || luaChon > 9 || checkMapGame == false);
			player = true;*/
		}
		if (WinGame() == -1)
		{
			system("cls");
			map->ShowMapGame();
			DAT::gotoXY(2, 12);
			std::cout << "\t    X WIN GAME";
			Exit();
		}
		else if (WinGame() == 1)
		{
			system("cls");
			map->ShowMapGame();
			DAT::gotoXY(2, 12);
			std::cout << "\t   PC WIN GAME";
			Exit();
		}
		else if (WinGame() == 0)
		{
			system("cls");
			map->ShowMapGame();
			DAT::gotoXY(2, 12);
			std::cout << "\t    HOA GAME";
			Exit();
		}
	}
	
	int GameManager::WinGame()
	{
		// sử dụng con trỏ tới hàng để không thể thay đỗi giá trị của MapGame
		int **mapGame = map->GetMapGame();
		for (int i = 0; i < 3; i++)
		{
			// kiểm tra theo hàng ngang
			// nếu hàng có cùng giá trị là -1 thì X WIN
			// nếu hàng có cùng giá trị là 1 thì O WIN
			if (mapGame[i][0] == mapGame[i][1] && mapGame[i][1] == mapGame[i][2])
			{
				if (mapGame[i][0] == -1) return -1;
				if (mapGame[i][0] == 1) return 1;
			}
			// kiểm tra theo cột
			// nếu cột có cùng giá trị là -1 thì X WIN
			// nếu cột có cùng giá trị là 1 thì O WIN
			else if (mapGame[0][i] == mapGame[1][i] && mapGame[1][i] == mapGame[2][i])
			{
				if (mapGame[0][i] == -1) return -1;
				if (mapGame[0][i] == 1) return 1;
			}
		}
		// kiểm tra theo đường chéo chính
		if (mapGame[0][0] == mapGame[1][1]&& mapGame[1][1] == mapGame[2][2])
		{
			if (mapGame[0][0] == -1) return -1;
			if (mapGame[0][0] == 1) return 1;
		}
		// kiểm tra đường chéo phụ
		if (mapGame[0][2] == mapGame[1][1] && mapGame[1][1] == mapGame[2][0])
		{
			if (mapGame[1][1] == -1) return -1;
			if (mapGame[1][1] == 1) return 1;
		}
		// kiểm tra map game còn trống hay không . nếu map game còn trống thì trả về false
		// => chưa kết thúc ván đấu
		bool temp = true;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (mapGame[i][j] == 0) temp = false;
			}
		}
		mapGame = NULL;
		// nếu map game không còn trống mà không trả về -1 hoặc 1 thì game Hòa trả về 0
		if (temp)
		{
			return 0;
		}
		return 2;
	}
	void GameManager::Run()
	{
		while (stateGame)
		{
			map->ShowMapGame();
			GamePlay();
			DAT::clearScreen();
		}
	}
	void GameManager::Exit()
	{
		stateGame = false;
	}
}
