/****************************************************************************************** 
 *	 DirectX Framework Version 11.12.17											  *	
 *	D3DGraphics.h																		  *
 *	Copyright 2011 PlanetChili <http://www.planetchili.net>								  *
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

#include <d3d9.h>
#include <math.h>
#include <stdlib.h>

class D3DGraphics
{
public:
// ================================================
// Public Member Functions
	D3DGraphics( HWND hWnd );
	~D3DGraphics();

	void PutPixel( int x, int y, int r, int g, int b );
	void DrawLine( float x1, float x2, float y1, float y2, int r, int g, int bl );
	void DrawPlayerPieceX( float x, float y, int r, int g, int b );
	void DrawPlayerPieceCircle( float x, float y, int r, int g, int b );
	void DrawCircle( float cx, float cy, float rad, int r, int g, int b );

	void BeginFrame();
	void EndFrame();

private:
// ================================================
// Private Member Variables
	IDirect3D9*			pDirect3D;
	IDirect3DDevice9*	pDevice;
};



