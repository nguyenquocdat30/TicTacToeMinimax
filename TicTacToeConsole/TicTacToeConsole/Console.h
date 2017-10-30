#pragma once
#ifndef  __CONSOLE_H_
#define __CONSOLE_H_
#include <Windows.h>
// các hàm cơ bản sử dụng với console
// như gotoXY, textColor ,...
namespace DAT
{
	void resizeConsole(int, int);
	void textColor(int);
	void gotoXY(int, int);
	void clearScreen();
}
#endif // ! __CONSOLE_H_