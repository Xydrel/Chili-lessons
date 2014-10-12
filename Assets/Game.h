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
#include <vector>

#define NPOO		1000  // Max number of poo
#define GOALRAD		10	  // Const radius of the disc
#define FRAMECOUNT	0	  // Starting frame count init value

class Game
{
public:
	Game( HWND hWnd,const KeyboardServer& kServer );

	void Go();

private:
	void ComposeFrame();

	void DrawFace( int x, int y );
	void DrawPoo( int x, int y );
	void DrawGameOver( int x, int y );
	void ResetGoal();

	void UpdateFace();
	void UpdatePoo();
	void ExitGame();

private:
	D3DGraphics gfx;
	KeyboardClient kbd;

	bool	gameIsOver;

	int		framesCounter;

	int		faceX;
	int		faceY;
	int		nPoo;							// An int to store the number of poo on the screen
	int		goalX;
	int		goalY;

	float	pooX[NPOO];
	float	pooY[NPOO];
	float	pooXVelocity[NPOO];
	float	pooYVelocity[NPOO];
};