#pragma once
#include <iostream>
#include "mylib.h"
using namespace std;

void walltop() {
	int x = 10, y = 1;
	while (x <= 100) {
		gotoXY(x, y);
		cout << "+";
		x++;
	}
}

void wallbottom() {
	int x = 10, y = 26;
	while (x <= 100) {
		gotoXY(x, y);
		cout << "+";
		x++;
	}
}

void wallright() {
	int x = 100, y = 1;
	while (y <= 26) {
		gotoXY(x, y);
		cout << "+";
		y++;
	}
}

void wallleft() {
	int x = 10, y = 1;
	while (y <= 26) {
		gotoXY(x, y);
		cout << "+";
		y++;
	}
}

void wall() {
	wallbottom();
	walltop();
	wallleft();
	wallright();
}