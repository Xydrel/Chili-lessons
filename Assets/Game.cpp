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
	, m_gameLogic( &gfx, &kbd )
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
	//if ( m_gameLogic != 0x00 )
	//{
		m_gameLogic.MoveCursorWithKeyboard();

		m_gameLogic.DrawGameBoard( m_iBaseX, m_iBaseY );
		m_gameLogic.DrawCursor( m_iBaseX + m_gameLogic.cursorX * m_iSquareSize, 
								m_iBaseY + m_gameLogic.cursorY * m_iSquareSize );
		for ( int iy = 0; iy < 3; iy++ )
		{
			for ( int ix = 0; ix < 3; ix++ )
			{
				if ( m_gameLogic.gameBoard.GetCellState(ix, iy) == GameBoard::X )
				{
					m_gameLogic.DrawX( m_iBaseX + ix * m_iSquareSize, m_iBaseY + iy * m_iSquareSize );
				}
				else if ( m_gameLogic.gameBoard.GetCellState( ix, iy ) == GameBoard::O )
				{
					m_gameLogic.DrawO( m_iBaseX + ix * m_iSquareSize, m_iBaseY + iy * m_iSquareSize );
				}
			}
		}


		// Debugging piece drawing at starting position
		/*m_gameLogic.DrawGameBoard( m_baseX, m_baseY );*/
		//m_gameLogic.DrawX( m_baseX, m_baseY );
		//m_gameLogic.DrawO( m_baseX + 100, m_baseY + 100 );
	//}

}