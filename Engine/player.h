#pragma once

class Player {
public:
	void clampPlayer();
	void clampBlaster();
	void shoot();

public:
	int x = 420;
	int y = 450;

	int speed = 2;

	int vx = 3;
	int vy = 3;

	int r = 255;
	int g = 255;
	int b = 255;

	int blasterX = x;
	int blasterY = y;

	int blasterVY = 0;

	bool inhibitBlast = false;

};