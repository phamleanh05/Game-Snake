#pragma once
#include <iostream>
#include "snake.h"
using namespace std;
bool gameover_wall(int xo, int yo) {
	if (yo == 1 && (xo >= 10 && xo <= 100)) {
		return true;
	}
	else if (yo == 26 && (xo >= 10 && xo <= 100)) {
		return true;
	}
	else if (xo == 100 && (yo >= 1 && yo <= 26)) {
		return true;
	}
	else if (xo == 10 && (yo >= 1 && yo <= 26)) {
		return true;
	}
	return false;
}

bool gameover_tail(int xsnake[],int ysnake[]) {
	for (int i = 1; i < num; i++) {
		if ((xsnake[0] == xsnake[i]) && (ysnake[0] == ysnake[i])) 
		{
			return true;
		}
	}
	return false;
}

bool over(int xsnake[],int ysnake[]) {
	bool over1 = gameover_wall(xsnake[0], ysnake[0]);
	bool over2 = gameover_tail(xsnake, ysnake);
	if (over1 == true || over2 == true) {
		return true;
	}
	return false;
}
