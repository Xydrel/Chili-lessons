
#include "GameLogic.h"

// --------------------------------------------------------------------------------
GameLogic::GameLogic( D3DGraphics* gfx, KeyboardClient* kbdClient )
	: m_pGfx( gfx )
	, m_Keyboardclient( kbdClient )
	, gameBoard( GameBoard() )
	, cursorX( 1 )
	, cursorY( 1 )
	, m_circlePlayer()
	, m_xplayer()
	, wasKeyPressedLastFrame( false )
	, player( gameBoard.playerA )
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
		m_xplayer->~PlayerX();
		m_xplayer = NULL;
	}
	if ( m_circlePlayer )
	{
		m_circlePlayer->~PlayerCircle();
		m_circlePlayer = NULL;
	}
	//if ( gameBoard )
	//{
	//	gameBoard->~GameBoard();
	//	gameBoard = NULL;
	//}
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
		m_pGfx->DrawLine( x + 8, y + 8, x + 48, y + 8, 0, 255, 100 );
		m_pGfx->DrawLine( x + 8, y + 9, x + 8, y + 48, 0, 255, 100 );
		m_pGfx->DrawLine( x + 91, y + 91, x + 51, y + 91, 0, 255, 100 );
		m_pGfx->DrawLine( x + 91, y + 90, x + 91, y + 51, 0, 255, 100 );
	}
}

// --------------------------------------------------------------------------------
void GameLogic::EndTurn()
{
	if ( gameBoard.curPlayer == gameBoard.playerA )
	{
		gameBoard.curPlayer = gameBoard.playerB;
	}
	else if ( gameBoard.curPlayer == gameBoard.playerB )
	{
		gameBoard.curPlayer = gameBoard.playerA;
	}
}

// --------------------------------------------------------------------------------
void GameLogic::DoUserInput()
{

}

// --------------------------------------------------------------------------------
void GameLogic::GameLoop()
{
	MovementInput();
}

// --------------------------------------------------------------------------------
void GameLogic::CheckPiecesOnBoard()
{
	bool XisWinner = false;
	bool OisWinner = false;
	bool isTieGame = false;

	if ( gameBoard.GetCellState( 0 ) == gameBoard.X &&
		 gameBoard.GetCellState( 1 ) == gameBoard.X && 
		 gameBoard.GetCellState( 2 ) == gameBoard.X ||
		 gameBoard.GetCellState( 3 ) == gameBoard.X &&
		 gameBoard.GetCellState( 4 ) == gameBoard.X &&
		 gameBoard.GetCellState( 5 ) == gameBoard.X ||
		 gameBoard.GetCellState( 6 ) == gameBoard.X &&
		 gameBoard.GetCellState( 7 ) == gameBoard.X &&
		 gameBoard.GetCellState( 8 ) == gameBoard.X ||
		 gameBoard.GetCellState( 0 ) == gameBoard.X &&
		 gameBoard.GetCellState( 3 ) == gameBoard.X &&
		 gameBoard.GetCellState( 6 ) == gameBoard.X ||
		 gameBoard.GetCellState( 1 ) == gameBoard.X &&
		 gameBoard.GetCellState( 4 ) == gameBoard.X &&
		 gameBoard.GetCellState( 7 ) == gameBoard.X ||
		 gameBoard.GetCellState( 2 ) == gameBoard.X &&
		 gameBoard.GetCellState( 5 ) == gameBoard.X &&
		 gameBoard.GetCellState( 8 ) == gameBoard.X ||
		 gameBoard.GetCellState( 0 ) == gameBoard.X &&
		 gameBoard.GetCellState( 4 ) == gameBoard.X &&
		 gameBoard.GetCellState( 8 ) == gameBoard.X ||
		 gameBoard.GetCellState( 2 ) == gameBoard.X &&
		 gameBoard.GetCellState( 4 ) == gameBoard.X &&
		 gameBoard.GetCellState( 6 ) == gameBoard.X )
	{
		// set playerA to winner
		printf( "X is the winner" );
		XisWinner = true;
	}
	else if ( gameBoard.GetCellState( 0 ) == gameBoard.O &&
			  gameBoard.GetCellState( 1 ) == gameBoard.O &&
			  gameBoard.GetCellState( 2 ) == gameBoard.O ||
			  gameBoard.GetCellState( 3 ) == gameBoard.O &&
			  gameBoard.GetCellState( 4 ) == gameBoard.O &&
			  gameBoard.GetCellState( 5 ) == gameBoard.O ||
			  gameBoard.GetCellState( 6 ) == gameBoard.O &&
			  gameBoard.GetCellState( 7 ) == gameBoard.O &&
			  gameBoard.GetCellState( 8 ) == gameBoard.O ||
			  gameBoard.GetCellState( 0 ) == gameBoard.O &&
			  gameBoard.GetCellState( 3 ) == gameBoard.O &&
			  gameBoard.GetCellState( 6 ) == gameBoard.O ||
			  gameBoard.GetCellState( 1 ) == gameBoard.O &&
			  gameBoard.GetCellState( 4 ) == gameBoard.O &&
			  gameBoard.GetCellState( 7 ) == gameBoard.O ||
			  gameBoard.GetCellState( 2 ) == gameBoard.O &&
			  gameBoard.GetCellState( 5 ) == gameBoard.O &&
			  gameBoard.GetCellState( 8 ) == gameBoard.O ||
			  gameBoard.GetCellState( 0 ) == gameBoard.O &&
			  gameBoard.GetCellState( 4 ) == gameBoard.O &&
			  gameBoard.GetCellState( 8 ) == gameBoard.O ||
			  gameBoard.GetCellState( 2 ) == gameBoard.O &&
			  gameBoard.GetCellState( 4 ) == gameBoard.O &&
			  gameBoard.GetCellState( 6 ) == gameBoard.O )
	{
		// set playerB to winner
		printf( "O is the winner" );
		OisWinner = true;
	}
	else if (!XisWinner && !OisWinner)
	{
		bool wasEmptyCell = false;
		int counter = 0;

		for ( int i = 0; i <= 8; ++i )
		{
			counter++;
			if ( gameBoard.GetCellState( i ) == gameBoard.EMPTY )
			{
				wasEmptyCell = true;
				break;
			}
		}

		if ( !wasEmptyCell && counter > 8 )
		{
			printf( "The Game was a Tie!" );
		}
	}
}

// --------------------------------------------------------------------------------
void GameLogic::MovementInput()
{
	if ( m_Keyboardclient )
	{
		if ( !wasKeyPressedLastFrame )
		{
			if ( m_Keyboardclient->RightIsPressed( ) )
			{
				wasKeyPressedLastFrame = true;
				cursorX++;
				if ( cursorX > 2 )
				{
					cursorX = 2;
				}
			}

			if ( m_Keyboardclient->LeftIsPressed( ) )
			{
				wasKeyPressedLastFrame = true;
				cursorX--;
				if ( cursorX < 0 )
				{
					cursorX = 0;
				}
			}

			if ( m_Keyboardclient->UpIsPressed( ) )
			{
				wasKeyPressedLastFrame = true;
				cursorY--;
				if ( cursorY < 0 )
				{
					cursorY = 0;
				}
			}

			if ( m_Keyboardclient->DownIsPressed( ) )
			{
				wasKeyPressedLastFrame = true;
				cursorY++;
				if ( cursorY > 2 )
				{
					cursorY = 2;
				}
			}
		}
		else if ( !(m_Keyboardclient->RightIsPressed() ||
					m_Keyboardclient->LeftIsPressed() ||
					m_Keyboardclient->UpIsPressed() ||
					m_Keyboardclient->DownIsPressed()) )
		{
			wasKeyPressedLastFrame = false;
		}

		if ( m_Keyboardclient->EnterIsPressed() &&
			 gameBoard.GetCellState( cursorX, cursorY ) == GameBoard::EMPTY)
		{
			// TODO: remove - debugging code

			/* this seems like the place that would work for adding the 
			 * player logic whic determins what players is conttrolling the cursor
			 * we can determin what player is controling the cursor then when the hit enter
			 * it places the piece representing the player.
			 */
			gameBoard.SetCellState( cursorX, cursorY, gameBoard.curPlayer );
			CheckPiecesOnBoard();

			GameLogic::EndTurn();
			
		}
	}
}
// --------------------------------------------------------------------------------
