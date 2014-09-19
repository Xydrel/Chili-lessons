
#include "D3DGraphics.h"
#include "Keyboard.h"
#include "GameBoard.h"
#include "PlayerCircle.h"
#include "PlayerX.h"
#include <string>


#define VERIFY(val) if (val == 0x00) EXCEPTION_EXIT_UNWIND

class GameLogic
{
public:
// =================================================
// Public Class Constructor
	GameLogic( D3DGraphics* gfx, KeyboardClient* kbdClient );
	~GameLogic();


private:
// =================================================
// Private Member Variables
	D3DGraphics*	m_pGfx;					// Pointer to gfx object to draw to screen
	KeyboardClient*	m_Keyboardclient;		// KeyboardClient to be used by the players
	PlayerCircle*	m_circlePlayer;			// Circle player object instance
	PlayerX*		m_xplayer;				// X player object instance pointer
	bool			m_gameOver;	   

	enum GameWinner
	{
		TIE,								// The game is a Tie
		WINNER_X,							// X player is the winner
		WINNER_O,							// O player is the winner
		NONE								// We have no winner
	};

	GameWinner		m_winner;				// Winner state field

private:
// =================================================
// Private Member Functions
	void DrawPlayerPieceCircle( float x, float y, int r, int g, int b );
	void DrawPlayerPieceX( float x, float y, int r, int g, int b );
	void DrawGrid(int x, int y);
	void DrawGameResults( int x, int y );

	void MovementInput();
	GameWinner CheckPiecesOnBoard();		// Evaluate the state of the board for a possible winner
	

public:
// =================================================
// Public Member Variables
	GameBoard		gameBoard;				// Game board object instance
	GameBoard::CellState player;
	int				cursorX;				// Cursor X position on the board
	int				cursorY;				// cursor Y position on the board
	bool			wasKeyPressedLastFrame;	// holds the state of if the keyboard key was previously pressed


// =================================================
// Public Member Functions
	void DrawGameBoard( int x, int y );		// Draws the game board on the screen
	void DrawX( int x, int y );				// Draw X piece at position x,y
	void DrawO( int x, int y );				// Draw O piece at position x,y
	void DrawCursor( int x, int y );		// Draw Cursor at position x,y

	void DoUserInput( );					// Obsolete
	void EndTurn( );						// End the turn of a player/ switch to next player
	void GameLoop( );						// Main game loop

};

