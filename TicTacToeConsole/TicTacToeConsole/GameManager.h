#pragma once
#ifndef __GAMEMANAGER_H_
#define __GAMEMANAGER_H_
#include "MapGame.h"
namespace TTT
{
	class GameManager
	{
	private:
		MapGame *map;
		// biến kiểm tra tới lượt người chơi nào
		bool player;
		// biến kiểm tra kết thúc game hay chưa
		bool stateGame;
		// hàm thực hiện xử lí người chơi
		void GamePlay();
		// hàm kiểm tra thắng thua
		// 1 X win
		// 2 O win
		int WinGame();
		// hàm kiểm tra map game còn trống hay không
		bool CheckMapGame(int,int);
		// hàm AI minimax 
		int MiniMax(int);
	public:
		GameManager();
		~GameManager();
		void Run();
		void Exit();
	};
}
#endif // !__GAMEMANAGER_H_


