
#include "D3DGraphics.h"
#include "GameBoard.h"
#include "PlayerCircle.h"
#include "PlayerX.h"


class GameLogic
{
public:
// =================================================
//Member Functions
	GameLogic( D3DGraphics* gfx );
	//~GameLogic();

	void m_DEBUG_DrawPlayerPieceCircle();	// Performs a draw of a player piece on the screen - testing the draw only
	void m_DEBUG_DrawPlayerPIeceX();		// Draws the x on screen for debugging
	void DrawGameBoard();					// Draws the game board on the screen

private:
// =================================================
//Member Functions

private:
// =================================================
//Member Variables
	D3DGraphics* m_pGfx;				// Pointer to gfx object to draw to screen
	PlayerCircle m_circlePlayer;		// Circle player object instance
	PlayerX*	 m_xplayer;				// X player object instance pointer
	GameBoard	 m_GameBoard;			// Game board object instance
	PlayerX		 m_xPlayerInstance;
};
