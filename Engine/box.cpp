#include "box.h"
#include "Graphics.h"


void Box::Update()
{
	x += vx;

	if (x < 10)
	{
		vx = -vx;
	}
	else if (x > Graphics::ScreenWidth - 10)
	{
		vx = -vx;
	}

}

void Box::collider(int bX, int bY, int eX, int eY)
{
	if (((bX - 3) <= eX + 7) && ((bX + 3) >= eX - 7) && ((bY + 3) >= eY - 7) && ((bY - 3) <= eY + 7))
	{
		isColliding = true;
	}

}
