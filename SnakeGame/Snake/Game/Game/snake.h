#pragma once
#include <iostream>
#include "mylib.h"
using namespace std;
int num = 7;

//-----Ran luc dau
void snake_start(int xsnake[], int ysnake[]) {
	int x = 50, y = 13;
	for (int i = 0; i < num; i++) {
		xsnake[i] = x;
		ysnake[i] = y;
		x--;
	}
}

//-----vẽ rắn
void draw_snake(int xsnake[],int ysnake[]) {
	for (int i = 0; i < num; i++) {
		gotoXY(xsnake[i], ysnake[i]);
		if (i == 0) {
			cout << "0";
		}
		else {
			cout << "o";
		}
	}
}

//-----xóa đuôi
void del_tail(int xsnake[], int ysnake[])
{
	for (int i = 0; i < num; i++)
	{
		gotoXY(xsnake[i], ysnake[i]);
		cout << " ";
	}
}

void add(int a[], int x) {
	for (int i = num; i > 0; i--) {
		a[i] = a[i - 1];
	}
	a[0] = x;
	num++;
}

void del(int a[], int ad) {
	for (int i = ad; i < num; i++) {
		a[i] = a[i + 1];
	}
	num--;
}

//-----kiểm tra rắn đè food
bool check_snake_food(int xfood, int yfood, int xsnake[], int ysnake[]) {
	for (int i = 0; i < num; i++) {
		if ((xfood == xsnake[i]) && (yfood == ysnake[i])) {
			return true;
		}
	}
	return false;
}

//-----kiểm tra food bị rắn ăn
bool check_food_snake(int xo, int yo, int xfood, int yfood)
{
	if ((xo == xfood) && (yo == yfood))
	{
		return true;
	}
	return false;
}

void food(int &xfood, int &yfood, int xsnake[],int ysnake[]) {
	do
	{
		//11 <= xfood <= 99, rand()%(b-a+1)+a;
		xfood = rand() % (99 - 11 + 1) + 11;
		//2 <= yfood <= 25
		yfood = rand() % (25 - 2 + 1) + 2;
	} while (check_snake_food(xfood, yfood, xsnake, ysnake) == true);
	gotoXY(xfood, yfood);
	cout << "@";
}


void snake_eat(int xsnake[], int ysnake[], int x, int y, int &xfood, int &yfood) {
	//b1: theem toa do moi vao dau mang
	add(xsnake, x);
	add(ysnake, y);
	if (check_food_snake(xfood, yfood, xsnake[0], ysnake[0]) == false)//-nếu thức ăn bị rắn ăn là sai thì xóa đuôi
	{
		//b2: xoa toa do cuoi mang
		del(xsnake, num - 1);
		del(ysnake, num - 1);
	}
	else 
	{
		food(xfood, yfood, xsnake, ysnake);
	}
	//b3: ve ran
	draw_snake(xsnake, ysnake);
}


