#include <iostream>
#include "Console.h"
#include "GameManager.h"
int main()
{
	// thay đỗi kích thức console
	DAT::resizeConsole(800,450);
	// thay đỗi màu hiển thị
	DAT::textColor(2);
	TTT::GameManager *game = new TTT::GameManager();
	game->Run();
	delete game;
	system("pause");
	return 0;
}