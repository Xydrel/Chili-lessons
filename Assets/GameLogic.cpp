
#include "GameLogic.h"

GameLogic::GameLogic( D3DGraphics* gfx )
{
	m_pGfx				= gfx;
	m_circlePlayer		= PlayerCircle();
	m_xPlayerInstance	= PlayerX();
	m_GameBoard			= GameBoard();
	m_xplayer			= m_xPlayerInstance.GetPlayerXInstance();
}

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

void GameLogic::m_DEBUG_DrawPlayerPieceCircle( )
{
	if ( m_pGfx )
	{
		m_pGfx->DrawPlayerPieceCircle( 500, 300, 255, 255, 255 );
	}
}

void GameLogic::m_DEBUG_DrawPlayerPIeceX()
{
	if ( m_pGfx )
	{
		// call gfx function to draw x
		m_pGfx->DrawPlayerPieceX( 260,340, 255,255,255 );
	}
}

void GameLogic::DrawGameBoard()
{
	if ( m_pGfx )
	{
		m_pGfx->DrawPlayBoard();
	}
}