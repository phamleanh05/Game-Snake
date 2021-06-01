#include <iostream>
#include "mylib.h"
#include "wall.h"
#include "snake.h"
#include "GameOver.h"
#define Max 100
using namespace std;

int main() {
	int xsnake[Max], ysnake[Max];
	wall();
	snake_start(xsnake,ysnake);
	draw_snake(xsnake, ysnake);
	//-----food
	srand(time(NULL));
	int xfood = 0, yfood = 0;
	food(xfood, yfood, xsnake, ysnake);
	bool gameover = false;
	int x = 50, y = 13;
	int check = 3;
	while (gameover == false) 
	{
		del_tail(xsnake, ysnake);
		if (_kbhit())
		{
			char kitu = _getch();
			if (kitu == -32)
			{
				kitu = _getch();
				if (kitu == 72 && check !=0)//dilen 
				{
					check = 1;
				}
				else if (kitu == 80 && check != 1)//di xuong
				{
					check = 0;
				}
				else if (kitu == 75 && check != 3)//sang trai
				{
					check = 2;
				}
				else if (kitu == 77 && check != 2)//sang phai
				{
					check = 3;
				}
			}
		}
		if (check == 0) {
			y++;
		}
		else if (check == 1) {
			y--;
		}
		else if (check == 2) {
			x--;
		}
		else if (check == 3) {
			x++;
		}
		snake_eat(xsnake, ysnake, x, y, xfood, yfood);
		gameover = over(xsnake,ysnake);
		Sleep(50);
	}
	_getch();
	return 0;
}
