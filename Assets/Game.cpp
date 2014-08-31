/****************************************************************************************** 
 *	 DirectX Framework Version 11.12.17											  *	
 *	Game.cpp																			  *
 *	Copyright 2011 PlanetChili.net														  *
 *																						  *
 *	This file is part of The  DirectX Framework.									  *
 *																						  *
 *	The  DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The  DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The  DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "Game.h"

Game::Game( HWND hWnd,const KeyboardServer& kServer )
	: gfx ( hWnd )
	, kbd( kServer )
	, m_logic( &gfx )
	, x( 400 )
	, y( 300 )
{}

void Game::Go()
{
	gfx.BeginFrame();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::ComposeFrame()
{
	// TODO: insert frame drawing code here
	
	//for (int y = 100; y < 300; y++)
	//{
	//	gfx.PutPixel(400, y, 255, 255, 255);
	//}

	if (kbd.RightIsPressed())
	{
		x++;
	}

	if (kbd.LeftIsPressed())
	{
		x--;
	}

	if (kbd.UpIsPressed())
	{
		y--;
	}

	if (kbd.DownIsPressed())
	{
		y++;
	}


	m_logic.m_DEBUG_DrawPlayerPieceCircle();
	m_logic.DrawGameBoard();


	//gfx.DrawLine( 500,50, 300, 400, 255, 255, 255 );
	//gfx.DrawCircle( x, y, 25, 255, 255, 255 );
}