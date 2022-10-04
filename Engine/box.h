#pragma once
#include <random>

class Box
{
	

public:

	int x = 0;
	int y = 0;
	double vx;
	int r = 0;
	int g = 0;
	int b = 0;
	bool isColliding = false;

	
	void Update();
	void collider(int bX, int bY, int eX, int eY);
};
