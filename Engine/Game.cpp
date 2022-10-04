/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <random>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<int> distX(10, Graphics::ScreenWidth - 10);
	std::uniform_int_distribution<int> distY(10, 300);

	box1.x = distX(rng);
	box1.y = distY(rng);
	box1.vx = 1;

	box2.x = distX(rng);
	box2.y = distY(rng);
	box2.vx = 1.2;

	box3.x = distX(rng);
	box3.y = distY(rng);
	box3.vx = 1.6;

	box4.x = distX(rng);
	box4.y = distY(rng);
	box4.vx = 2;

	//cyan
	box1.r = 0;
	box1.g = 255;
	box1.b = 255;

	//orange
	box2.r = 255;
	box2.g = 165;
	box2.b = 0;

	//purple
	box3.r = 255;
	box3.g = 0;
	box3.b = 255;

	//lime green
	box4.r = 50;
	box4.g = 190;
	box4.b = 50;

}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	move(player.speed);

	//This function keeps player and blaster on screen
	player.clampPlayer();
	player.clampBlaster();

	if (wnd.kbd.KeyIsPressed(VK_SPACE))
	{
		player.shoot();
	}
	else {
		player.blasterY = player.y;
		player.blasterX = player.x;
	}

	player.blasterY = player.blasterY + player.blasterVY;


	box1.Update();
	box1.collider(player.blasterX, player.blasterY, box1.x, box1.y);

	box2.Update();
	box2.collider(player.blasterX, player.blasterY, box2.x, box2.y);

	box3.Update();
	box3.collider(player.blasterX, player.blasterY, box3.x, box3.y);

	box4.Update();
	box4.collider(player.blasterX, player.blasterY, box4.x, box4.y);

}

void Game::ComposeFrame()
{
	drawReticle(player.x, player.y, player.r, player.g, player.b);
    drawBlast();

	if (box1.isColliding == false)
	{
		drawEnemyBox(box1.x, box1.y, box1.r, box1.g, box1.b);
	}

	if (box2.isColliding == false)
	{
		drawEnemyBox(box2.x, box2.y, box2.r, box2.g, box2.b);
	}

	if (box3.isColliding == false)
	{
		drawEnemyBox(box3.x, box3.y, box3.r, box3.g, box3.b);
	}

	if (box4.isColliding == false)
	{
		drawEnemyBox(box4.x, box4.y, box4.r, box4.g, box4.b);
	}

}

void Game::drawReticle(int x, int y, int r, int g, int b)
{
	gfx.PutPixel(x + 2, y, r, g, b);
	gfx.PutPixel(x + 3, y, r, g, b);
	gfx.PutPixel(x + 4, y, r, g, b);
	gfx.PutPixel(x + 5, y, r, g, b);
	gfx.PutPixel(x - 2, y, r, g, b);
	gfx.PutPixel(x - 3, y, r, g, b);
	gfx.PutPixel(x - 4, y, r, g, b);
	gfx.PutPixel(x - 5, y, r, g, b);
	gfx.PutPixel(x, y - 2, r, g, b);
	gfx.PutPixel(x, y - 3, r, g, b);
	gfx.PutPixel(x, y - 4, r, g, b);
	gfx.PutPixel(x, y - 5, r, g, b);
	gfx.PutPixel(x, y + 2, r, g, b);
	gfx.PutPixel(x, y + 3, r, g, b);
	gfx.PutPixel(x, y + 4, r, g, b);
	gfx.PutPixel(x, y + 5, r, g, b);
}
void Game::drawBlast()
{
	gfx.PutPixel(player.blasterX, player.blasterY, 255, 234, 0);
	gfx.PutPixel(player.blasterX + 1, player.blasterY, 255, 234, 0);
	gfx.PutPixel(player.blasterX + 2, player.blasterY, 255, 234, 0);

	gfx.PutPixel(player.blasterX, player.blasterY - 1, 255, 234, 0);
	gfx.PutPixel(player.blasterX + 1, player.blasterY - 1, 255, 234, 0);
	gfx.PutPixel(player.blasterX + 2, player.blasterY - 1, 255, 234, 0);

	gfx.PutPixel(player.blasterX, player.blasterY - 2, 255, 234, 0);
	gfx.PutPixel(player.blasterX + 1, player.blasterY - 2, 255, 234, 0);
	gfx.PutPixel(player.blasterX + 2, player.blasterY - 2, 255, 234, 0);
	
}
void Game::drawEnemyBox(int x, int y, int r, int g, int b)
{
	
	gfx.PutPixel(x + 1 + 5, y  - 5 - 5, r, g, b);
	gfx.PutPixel(x + 2 + 5, y  - 5 - 5, r, g, b);
	gfx.PutPixel(x + 3 + 5, y  - 5 - 5, r, g, b);
	gfx.PutPixel(x + 4 + 5, y  - 5 - 5, r, g, b);
	gfx.PutPixel(x + 5 + 5, y  - 5 - 5, r, g, b);
	gfx.PutPixel(x + 5 + 5, y  - 4 - 5, r, g, b);
	gfx.PutPixel(x + 5 + 5, y  - 3 - 5, r, g, b);
	gfx.PutPixel(x + 5 + 5, y  - 2 - 5, r, g, b);
	gfx.PutPixel(x + 5 + 5, y  - 1 - 5, r, g, b);
						 				   	  
	gfx.PutPixel(x - 1 - 5, y  - 5 - 5, r, g, b);
	gfx.PutPixel(x - 2 - 5, y  - 5 - 5, r, g, b);
	gfx.PutPixel(x - 3 - 5, y  - 5 - 5, r, g, b);
	gfx.PutPixel(x - 4 - 5, y  - 5 - 5, r, g, b);
	gfx.PutPixel(x - 5 - 5, y  - 5 - 5, r, g, b);
	gfx.PutPixel(x - 5 - 5, y  - 4 - 5, r, g, b);
	gfx.PutPixel(x - 5 - 5, y  - 3 - 5, r, g, b);
	gfx.PutPixel(x - 5 - 5, y  - 2 - 5, r, g, b);
	gfx.PutPixel(x - 5 - 5, y  - 1 - 5, r, g, b);
						 				   	  
	gfx.PutPixel(x - 1 - 5, y  + 5 + 5, r, g, b);
	gfx.PutPixel(x - 2 - 5, y  + 5 + 5, r, g, b);
	gfx.PutPixel(x - 3 - 5, y  + 5 + 5, r, g, b);
	gfx.PutPixel(x - 4 - 5, y  + 5 + 5, r, g, b);
	gfx.PutPixel(x - 5 - 5, y  + 5 + 5, r, g, b);
	gfx.PutPixel(x - 5 - 5, y  + 4 + 5, r, g, b);
	gfx.PutPixel(x - 5 - 5, y  + 3 + 5, r, g, b);
	gfx.PutPixel(x - 5 - 5, y  + 2 + 5, r, g, b);
	gfx.PutPixel(x - 5 - 5, y  + 1 + 5, r, g, b);
						 				  
	gfx.PutPixel(x + 1 + 5, y  + 5 + 5, r, g, b);
	gfx.PutPixel(x + 2 + 5, y  + 5 + 5, r, g, b);
	gfx.PutPixel(x + 3 + 5, y  + 5 + 5, r, g, b);
	gfx.PutPixel(x + 4 + 5, y  + 5 + 5, r, g, b);
	gfx.PutPixel(x + 5 + 5, y  + 5 + 5, r, g, b);
	gfx.PutPixel(x + 5 + 5, y  + 4 + 5, r, g, b);
	gfx.PutPixel(x + 5 + 5, y  + 3 + 5, r, g, b);
	gfx.PutPixel(x + 5 + 5, y  + 2 + 5, r, g, b);
	gfx.PutPixel(x + 5 + 5, y  + 1 + 5, r, g, b);

}

void Game::move(int speed)
{
	if (wnd.kbd.KeyIsPressed(VK_RIGHT))
	{
		player.x = player.x + speed;
	}

	if (wnd.kbd.KeyIsPressed(VK_LEFT))
	{
		player.x = player.x - speed;
	}

	if (wnd.kbd.KeyIsPressed(VK_DOWN))
	{
		player.y = player.y + speed;
	}

	if (wnd.kbd.KeyIsPressed(VK_UP))
	{
		player.y = player.y - speed;
	}
}




