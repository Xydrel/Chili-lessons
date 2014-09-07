
#include "GameLogic.h"

// --------------------------------------------------------------------------------
GameLogic::GameLogic( D3DGraphics* gfx, KeyboardClient* kbdClient )
	: m_pGfx( gfx )
	, m_Keyboardclient( kbdClient )
	, gameBoard( GameBoard::GameBoard() )
	, cursorX( 1 )
	, cursorY( 1 )
	, m_circlePlayer( PlayerCircle::PlayerCircle() )
	, m_xPlayerInstance( PlayerX::PlayerX() )
	, m_xplayer( m_xPlayerInstance.GetPlayerXInstance() )
{}

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
void GameLogic::DrawGameBoard(int x, int y)
{
	DrawGrid( x, y );
}

// --------------------------------------------------------------------------------
void GameLogic::DrawPlayerPieceX( float x, float y, int r, int g, int b )
{
	if ( m_pGfx )
	{
		m_pGfx->DrawLine( x + 15, y + 15, x+ 84, y + 84, r, g, b );
		m_pGfx->DrawLine( x + 15, y + 84, x+ 84, y + 15, r, g, b );
	}
}

// --------------------------------------------------------------------------------
void GameLogic::DrawPlayerPieceCircle( float x, float y, int r, int g, int b )
{
	if ( m_pGfx )
	{
		m_pGfx->DrawCircle( x, y, 35, r, g, b );
	}
}

// --------------------------------------------------------------------------------
void GameLogic::DrawX( int x, int y)
{
	// Draw the X game piece
	DrawPlayerPieceX( x, y, 255, 0, 0 );
}

// --------------------------------------------------------------------------------
void GameLogic::DrawO( int x, int y )
{
	// Draw the O game piece
	DrawPlayerPieceCircle( x + 49, y + 49, 0, 0, 255 );
}

// --------------------------------------------------------------------------------
void GameLogic::DrawGrid(int x, int y)
{
	if ( m_pGfx )
	{
		m_pGfx->DrawLine( 0 + x,	0 + y,	 299 + x, 0 + y,   255, 255, 255 );		// draw top line
		m_pGfx->DrawLine( 0 + x,	299 + y, 299 + x, 299 + y, 255, 255, 255 );		// draw bottom
		m_pGfx->DrawLine( 0 + x,	199 + y, 299 + x, 199 + y, 255, 255, 255 );		// draw lower cross line
		m_pGfx->DrawLine( 0 + x,	99 + y,	 299 + x, 99 + y,  255, 255, 255 );		// draw top cross line
		m_pGfx->DrawLine( 0 + x,	0 + y,	 0 + x,	  299 + y, 255, 255, 255 );		// draw left side
		m_pGfx->DrawLine( 299 + x,	0 + y,	 299 + x, 299 + y, 255, 255, 255 );		// draw right side
		m_pGfx->DrawLine( 99 + x,	0 + y,	 99 + x,  299 + y, 255, 255, 255 );		// draw left inside side
		m_pGfx->DrawLine( 199 + x,	0 + y,	 199 + x, 299 + y, 255, 255, 255 );		// draw right inside side
	}
}

// --------------------------------------------------------------------------------
void GameLogic::DrawCursor( int x, int y )
{
	if ( m_pGfx )
	{
		m_pGfx->DrawLine( x + 8, y + 8, x + 48, y + 8, 0, 255, 0 );
		m_pGfx->DrawLine( x + 8, y + 9, x + 8, y + 48, 0, 255, 0 );
		m_pGfx->DrawLine( x + 91, y + 91, x + 51, y + 91, 0, 255, 0 );
		m_pGfx->DrawLine( x + 91, y + 90, x + 91, y + 51, 0, 255, 0 );
	}
}

// --------------------------------------------------------------------------------
void GameLogic::MoveCursorWithKeyboard()
{
	if ( m_Keyboardclient )
	{
		if ( m_Keyboardclient->RightIsPressed( ) )
		{
			cursorX++;
			if ( cursorX > 2 )
			{
				cursorX = 2;
			}
		}

		if ( m_Keyboardclient->LeftIsPressed( ) )
		{
			cursorX--;
			if ( cursorX < 0 )
			{
				cursorX = 0;
			}
		}

		if ( m_Keyboardclient->UpIsPressed( ) )
		{
			cursorY--;
			if ( cursorY < 0 )
			{
				cursorY = 0;
			}
		}

		if ( m_Keyboardclient->DownIsPressed( ) )
		{
			cursorY++;
			if ( cursorY > 2 )
			{
				cursorY = 2;
			}
		}
	}
}

// --------------------------------------------------------------------------------