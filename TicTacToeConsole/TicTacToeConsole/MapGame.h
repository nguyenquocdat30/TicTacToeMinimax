#pragma once
#ifndef __MAPGAME_H_
#define __MAPGAME_H_
#define ROW_MAPGAME 3
#define COLUMN_MAPGAME 3
class MapGame
{
private:
	int **mapGame;
	// Hàm chuyển đỗi ( vì mảng map là 1 mảng chứa các số 0 . nên chuyển đỗi để in ra màn hình ' ' )
	char gridChar(int);
public:
	MapGame();
	~MapGame();
	// hàm hiển thị map game 
	void ShowMapGame();
	// hàm setter thay đôi giá trị trong mảng map game  int giá trị , int vị trí X , int vị trí Y
	void SetMapGame(int,int,int);
	// setter int giá trị , int vị trí
	void SetMapGame(int, int);
	// hàm getter , sử dụng con trỏ cấp 2 trỏ về biến **mapGame
	int **GetMapGame();
	// hàm kiểm tra map tại vị trí đó còn trống không
	bool CheckMapGame(int);
	
};
#endif // !__MAPGAME_H_