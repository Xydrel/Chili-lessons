/****************************************************************************************** 
 *	 DirectX Framework Version 11.12.17											  *	
 *	Game.h																				  *
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
#pragma once

#include "D3DGraphics.h"
#include "Keyboard.h"
#include "GameLogic.h"

class Game
{
// ================================================
// Public Member Constructor
public:
	Game( HWND hWnd,const KeyboardServer& kServer );
	void Go();

// ================================================
// Private Member Functions
private:
	void ComposeFrame();

// ================================================
// Private Member Variables
private:
	D3DGraphics		gfx;
	KeyboardClient	kbd;
	GameLogic		m_gameLogic;
	const int		m_baseX = 250;					// const baseX offset
	const int		m_baseY	= 150;					// const baseY offset
};