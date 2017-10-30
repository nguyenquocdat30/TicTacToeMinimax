#include "MapGame.h"
#include <iostream>
MapGame::MapGame()
{
	mapGame = new int* [ROW_MAPGAME];
	for (int i = 0; i < ROW_MAPGAME; i++)
	{
		mapGame[i] = new int[COLUMN_MAPGAME];
	}
	for (int i = 0; i < ROW_MAPGAME; i++)
	{
		for (int j = 0; j < COLUMN_MAPGAME; j++)
		{
			mapGame[i][j] = 0;
		}
	}
}

MapGame::~MapGame()
{
	for (int i = 0; i < ROW_MAPGAME; i++)
	{
		delete[] mapGame[i];
	}
	delete[]mapGame;
}

void MapGame::ShowMapGame()
{
	std::cout << "    GAME TIC TAC TOE 2 PLAYER \n";
	std::cout << "---------------------------------\n";
	for (int i = 0; i < ROW_MAPGAME; i++)
	{
		for (int j = 0; j < COLUMN_MAPGAME; j++)
		{
			std::cout <<"|    "<<gridChar(mapGame[i][j])<< "    |";
		}
		std::cout <<"\n---------------------------------\n";
	}
}
void MapGame::SetMapGame(int value,int value1,int value2)
{
	mapGame[value1][value2] = value;
}
void MapGame::SetMapGame(int value, int vitri)
{
	switch (vitri)
	{
		case 1:
			mapGame[0][0] = value;
			break;
		case 2:
			mapGame[0][1] = value;
			break;
		case 3:
			mapGame[0][2] = value;
			break;
		case 4:
			mapGame[1][0] = value;
			break;
		case 5:
			mapGame[1][1] = value;
			break;
		case 6:
			mapGame[1][2] = value;
			break;
		case 7:
			mapGame[2][0] = value;
			break;
		case 8:
			mapGame[2][1] = value;
			break;
		case 9:
			mapGame[2][2] = value;
			break;
		default:
			break;
	}
}
bool MapGame::CheckMapGame(int value)
{
	switch (value)
	{
		case 1:
			if (mapGame[0][0] == 0) return true;
			else return false; break;
		case 2:
			if (mapGame[0][1] == 0) return true;
			else return false; break;
		case 3:
			if (mapGame[0][2] == 0) return true;
			else return false; break;
		case 4:
			if (mapGame[1][0] == 0) return true;
			else return false; break;
		case 5:
			if (mapGame[1][1] == 0) return true;
			else return false; break;
		case 6:
			if (mapGame[1][2] == 0) return true;
			else return false; break;
		case 7:
			if (mapGame[2][0] == 0) return true;
			else return false; break;
		case 8:
			if (mapGame[2][1] == 0) return true;
			else return false; break;
		case 9:
			if (mapGame[2][2] == 0) return true;
			else return false; break;
		default: return false; break;
	}
}
int** MapGame::GetMapGame()
{
	return mapGame;
}
char MapGame::gridChar(int i)
{
	switch (i)
	{
		case -1: return 'X';
		case 0: return ' ';
		case 1: return 'O';
	}
	return '!';
}
