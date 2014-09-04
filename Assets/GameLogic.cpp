
#include "GameLogic.h"

// --------------------------------------------------------------------------------
GameLogic::GameLogic( D3DGraphics* gfx )
{
	m_pGfx				= gfx;
	m_circlePlayer		= PlayerCircle();
	m_xPlayerInstance	= PlayerX();
	m_GameBoard			= GameBoard();								// creating the GameBoard
	m_xplayer			= m_xPlayerInstance.GetPlayerXInstance();	// Creating the playerx instance

}

// --------------------------------------------------------------------------------
GameLogic::~GameLogic()
{
	if ( m_pGfx )
	{
		m_pGfx->~D3DGraphics();
		m_pGfx = NULL;
	}
	if ( m_xplayer )
	{
		m_xplayer = NULL;
	}
}

// --------------------------------------------------------------------------------
void GameLogic::m_DEBUG_DrawPlayerPieceCircle( )
{
	DrawPlayerPieceCircle( 500, 300, 255, 255, 255 );
}

// --------------------------------------------------------------------------------
void GameLogic::m_DEBUG_DrawPlayerPIeceX()
{
	// call gfx function to draw x
	DrawPlayerPieceX( 260,340, 255,255,255 );
}

// --------------------------------------------------------------------------------
void GameLogic::DrawGameBoard(int x, int y)
{
	DrawGrid( x, y );
}

// --------------------------------------------------------------------------------
void GameLogic::DrawPlayerPieceX( float x, float y, int r, int g, int b )
{
	if ( m_pGfx )
	{
		m_pGfx->DrawLine( x, y, 110, 190, r, g, b );
		m_pGfx->DrawLine( x, y, 190, 110, r, g, b );
	}

	// there will actually have to be game logic to determine which row
	// to draw the x on and pass that into this function.
}

// --------------------------------------------------------------------------------
void GameLogic::DrawPlayerPieceCircle( float x, float y, int r, int g, int b )
{
	if ( m_pGfx )
	{
		m_pGfx->DrawCircle( x, y, 40, r, g, b );
	}
}

// --------------------------------------------------------------------------------
void GameLogic::DrawX( int x, int y )
{
	// Draw the X game piece
	DrawPlayerPieceX( x, y, 255, 255, 255 );
}

// --------------------------------------------------------------------------------
void GameLogic::DrawO( int x, int y )
{
	// Draw the O game piece
}

// --------------------------------------------------------------------------------
void GameLogic::DrawGrid(int x, int y)
{
	if ( m_pGfx )
	{
		m_pGfx->DrawLine( 0 + x, 299 + x, 0 + y, 0 + y, 255, 255, 255 );		// draw top line
		m_pGfx->DrawLine( 0 + x, 299 + x, 299 + y, 299 + y, 255, 255, 255 );	// draw bottom
		m_pGfx->DrawLine( 0 + x, 299 + x, 199 + y, 199 + y, 255, 255, 255 );	// draw lower cross line
		m_pGfx->DrawLine( 0 + x, 299 + x, 99 + y, 99 + y, 255, 255, 255 );		// draw top cross line
		m_pGfx->DrawLine( 0 + x, 0 + x, 0 + y, 299 + y, 255, 255, 255 );		// draw left side
		m_pGfx->DrawLine( 299 + x, 299 + x, 0 + y, 299 + y, 255, 255, 255 );	// draw right side
		m_pGfx->DrawLine( 99 + x, 99 + x, 0 + y, 299 + y, 255, 255, 255 );		// draw left inside side
		m_pGfx->DrawLine( 199 + x, 199 + x, 0 + y, 299 + y, 255, 255, 255 );	// draw right inside side
	}
}

// --------------------------------------------------------------------------------