
#include "GameLogic.h"

GameLogic::GameLogic( D3DGraphics* gfx )
{
	m_pGfx				= gfx;
	m_circlePlayer		= PlayerCircle();
	m_xPlayerInstance	= PlayerX();
	m_GameBoard			= GameBoard();
	m_xplayer			= m_xPlayerInstance.GetPlayerXInstance();
}

void GameLogic::m_DEBUG_DrawPlayerPieceCircle( )
{
	m_pGfx->DrawPlayerPieceCircle( 500, 300, 255, 255, 255 );
}

void GameLogic::m_DEBUG_DrawPlayerPIeceX()
{
	// call gfx function to draw x
}

void GameLogic::DrawGameBoard()
{
	m_pGfx->DrawPlayBoard();
}