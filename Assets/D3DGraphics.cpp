/****************************************************************************************** 
 *	 DirectX Framework Version 11.12.17											  *	
 *	D3DGraphics.cpp																		  *
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

#include "D3DGraphics.h"

D3DGraphics::D3DGraphics( HWND hWnd )
{
	pDirect3D = Direct3DCreate9( D3D_SDK_VERSION );

    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory( &d3dpp,sizeof( d3dpp ) );
    d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;
	d3dpp.Flags = D3DPRESENTFLAG_LOCKABLE_BACKBUFFER;

    pDirect3D->CreateDevice( D3DADAPTER_DEFAULT,D3DDEVTYPE_HAL,hWnd,
		D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_PUREDEVICE,&d3dpp,&pDevice );
}

D3DGraphics::~D3DGraphics()
{
	if( pDevice )
	{
		pDevice->Release();
		pDevice = NULL;
	}
	if( pDirect3D )
	{
		pDirect3D->Release();
		pDirect3D = NULL;
	}
}

void D3DGraphics::PutPixel( int x,int y,int r,int g,int b )
{
	IDirect3DSurface9* pBackBuffer = NULL;
	D3DLOCKED_RECT rect;

	pDevice->GetBackBuffer( 0,0,D3DBACKBUFFER_TYPE_MONO,&pBackBuffer );
	pBackBuffer->LockRect( &rect,NULL,NULL );
	((D3DCOLOR*)rect.pBits)[ x + (rect.Pitch >> 2) * y ] = D3DCOLOR_XRGB( r,g,b );
	pBackBuffer->UnlockRect();
	pBackBuffer->Release();
}

void D3DGraphics::BeginFrame()
{
	pDevice->Clear( 0,NULL,D3DCLEAR_TARGET,D3DCOLOR_XRGB(0,0,0),0.0f,0 );
}

void D3DGraphics::EndFrame()
{
	pDevice->Present( NULL,NULL,NULL,NULL );
}

void D3DGraphics::DrawLine( float x1, float x2, float  y1, float y2, int r, int g, int bl )
{
	// Function to draw a pixel line.
	float dy = y2 - y1;
	float dx = x2 - x1;

	if ( abs(dy) > abs(dx) )
	{
		if ( y1 > y2 )
		{
			float temp = y2;
			y2	 = y1;
			y1	 = temp;
			temp = x2;
			x2	 = x1;
			x1 = temp;
		}
		float m = ( float )dx / ( float )dy;
		float b = x1 - m*y1 + 0.5F;
		for ( float y = y1; y <= y2; y++ )
		{
			float x = m*y + b;  // slope intercept form
			PutPixel( x, y, r, g, bl );
		}
	}
	else
	{
		if ( x1 > x2 )
		{
			float temp = y2;
			y2 = y1;
			y1 = temp;
			temp = x2;
			x2 = x1;
			x1 = temp;
		}
		float m = ( float )dy / ( float )dx;
		float b = y1 - m*x1;
		for ( float x = x1; x <= x2; x++ )
		{
			float y = m*x+b + 0.5F;  // slope intercept form
			PutPixel( x, y, r, g, bl );
		}
	}
}

void D3DGraphics::DrawCircle( float cx, float cy, float rad, int r, int g, int b )
{
	// Needs center x and y location on a quadratic plane.
	// Equation of a point for a circle
	// y = sqrt of r^2 - x^2

	float radSqr = rad * rad;

	// Chili Solution
	float x0 = 0.70710685F*rad + 0.5F;
	for ( float x = 0; x <= x0; ++x )
	{
		float y = sqrt( radSqr - x*x ) + 0.5F;
		//PutPixel( cx, cy, 255, 0, 0 );  // draw pixel at center of circle
		PutPixel( cx + x, cy + y, r, g, b );
		PutPixel( cx + y, cy + x, r, g, b );
		PutPixel( cx - x, cy + y, r, g, b );
		PutPixel( cx - y, cy + x, r, g, b );
		PutPixel( cx - x, cy - y, r, g, b );
		PutPixel( cx - y, cy - x, r, g, b );
		PutPixel( cx + x, cy - y, r, g, b );
		PutPixel( cx + y, cy - x, r, g, b );
	}

	//for ( float x = -rad; x <= rad; ++x )
	//{
	//	float y = sqrt( radSqr - x*x ) + 0.5F;
	//	PutPixel( cx + x, cy + y, r, g, b );
	//	PutPixel( cx - x, cy - y, r, g, b );
	//}
	//for ( float y = +rad; y >= -rad; --y )
	//{
	//	float x = sqrt( radSqr - y*y ) + 0.5F;
	//	PutPixel( cx + x, cy + y, r, g, b );
	//	PutPixel( cx - x, cy - y, r, g, b );
	//}
}

void D3DGraphics::DrawPlayerPieceX( float x, float y, int r, int g, int b )
{
	// since the draw line function is programed the way it is
	// the lines for the 'x' will have to be offset from center (x,y)
	DrawLine( x, y, 110, 190, r, g, b );
	DrawLine( x, y, 190, 110, r, g, b );

	// there will actually have to be game logic to determine which row
	// to draw the x on and pass that into this function.
}

void D3DGraphics::DrawPlayerPieceCircle( float x, float y, int r, int g, int b )
{
	DrawCircle( x, y, 40, r, g, b );
}

void D3DGraphics::DrawPlayBoard()
{
	DrawLine( 200, 600, 100, 100, 255, 255, 255 );  // draw top line
	DrawLine( 200, 600, 500, 500, 255, 255, 255 );  // draw bottom
	DrawLine( 200, 600, 370, 370, 255, 255, 255 );  // draw lower cross line
	DrawLine( 200, 600, 230, 230, 255, 255, 255 );  // draw top cross line
	DrawLine( 200, 200, 100, 500, 255, 255, 255 );  // draw left side
	DrawLine( 600, 600, 100, 500, 255, 255, 255 );  // draw right side
	DrawLine( 333, 333, 100, 500, 255, 255, 255 );  // draw left inside side
	DrawLine( 466, 466, 100, 500, 255, 255, 255 );  // draw right inside side
}