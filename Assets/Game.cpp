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

// --------------------------------------------------------------------------------
Game::Game( HWND hWnd,const KeyboardServer& kServer )
	: gfx ( hWnd )
	, kbd( kServer )
	, m_gameLogic( &gfx )
{}

// --------------------------------------------------------------------------------
void Game::Go()
{
	gfx.BeginFrame();
	ComposeFrame();
	gfx.EndFrame();
}

// --------------------------------------------------------------------------------
void Game::ComposeFrame()
{
	// TODO: insert frame drawing code here


	//if (kbd.RightIsPressed())
	//{
	//	x++;
	//}

	//if (kbd.LeftIsPressed())
	//{
	//	x--;
	//}

	//if (kbd.UpIsPressed())
	//{
	//	y--;
	//}

	//if (kbd.DownIsPressed())
	//{
	//	y++;
	//}


	// Debugging piece drawing at starting position
	m_gameLogic.DrawGameBoard( m_baseX, m_baseY );
	m_gameLogic.DrawX( m_baseX, m_baseY );
	m_gameLogic.DrawO( m_baseX + 100, m_baseY + 100 );

}