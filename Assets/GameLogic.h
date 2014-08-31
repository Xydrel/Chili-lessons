
#include "D3DGraphics.h"
#include "GameBoard.h"
#include "PlayerCircle.h"
#include "PlayerX.h"


class GameLogic
{
public:
// =================================================
//Member Functions
	GameLogic( D3DGraphics* gfx ) 
	{ 
		m_pGfx			= gfx;
		//m_circlePlayer	= PlayerCircle();
		//m_xplayer		= PlayerX();
		//m_GameBoard		= GameBoard();
	}
	//~GameLogic();

private:
// =================================================
//Member Functions
	void DrawPlayerPiece();

private:
// =================================================
//Member Variables
	D3DGraphics* m_pGfx;
	//PlayerCircle m_circlePlayer;
	//PlayerX		 m_xplayer;
	//GameBoard	 m_GameBoard;
};

