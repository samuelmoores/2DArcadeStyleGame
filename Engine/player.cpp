#include "player.h"
#include "Graphics.h"

void Player::clampPlayer()
{
	if (x < 5)
	{
		x = 5;
	}
	else if (x > Graphics::ScreenWidth - 6)
	{
		x = Graphics::ScreenWidth - 6;
	}

	if (y < 400)
	{
		
		y = 400;
	}
	else if (y > Graphics::ScreenHeight - 6)
	{
		
		y = Graphics::ScreenHeight - 6;
	}
}

void Player::clampBlaster()
{
	if (blasterY - 8 <= 0)
	{

		blasterVY++;
	}

	if (blasterY + 8 >= Graphics::ScreenHeight)
	{
		blasterVY--;
	}
}

void Player::shoot()
{
	if (inhibitBlast)
	{

	}
	else {
		blasterVY = blasterVY - 3;
		inhibitBlast = true;
	}
}
