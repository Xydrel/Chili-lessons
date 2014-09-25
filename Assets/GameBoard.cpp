
#include "GameBoard.h"

#include <time.h>
#include<algorithm>

// --------------------------------------------------------------------------------
GameBoard::GameBoard()
{
	for ( int index = 0; index < 9; index++ )
	{
		SetCellState( index, EMPTY );
	}

	//gb = new GameBoard();

	// Temp Code to draw player pieces
	//SetCellState( 0, 0, X );
	//SetCellState( 1, 1, O );
}

// --------------------------------------------------------------------------------
GameBoard::~GameBoard()
{
	//if ( gb )
	//{
	//	delete gb;
	//	gb = NULL;
	//}
}

// --------------------------------------------------------------------------------
void GameBoard::SetCellState(int index, CellState state)
{
	switch ( index )
	{
		case 0: s0 = state; break;
		case 1: s1 = state; break;
		case 2: s2 = state; break;
		case 3: s3 = state; break;
		case 4: s4 = state; break;
		case 5: s5 = state; break;
		case 6: s6 = state; break;
		case 7: s7 = state; break;
		case 8: s8 = state; break;
		default: break;
	}
}

// --------------------------------------------------------------------------------
void GameBoard::SetCellState( int ix, int iy, CellState state )
{
	int index = iy * 3 + ix;
	SetCellState( index, state );
}


// --------------------------------------------------------------------------------
GameBoard::CellState GameBoard::GetCellState( int index )
{
	switch ( index )
	{
		case 0: return s0;
		case 1: return s1;
		case 2: return s2;
		case 3: return s3;
		case 4: return s4;
		case 5: return s5;
		case 6: return s6;
		case 7: return s7;
		case 8: return s8;
		default: return EMPTY;
	}
}

GameBoard::CellState GameBoard::GetCellState( int ix, int iy )
{
	int index = iy * 3 + ix;
	return GetCellState( index );
}

GameBoard::CellState GameBoard::SetStartingPlayer()
{
	int selection = randomSelectPlayer();
	if ( selection == 0 ) curPlayer = playerA;
	else if ( selection == 1 ) curPlayer = playerB;

	return curPlayer;
}

int GameBoard::randomSelectPlayer()
{
	srand( time( NULL ) );

	unsigned int result = rand() % 100;

	if ( result <= 49 ) return 0;
	else if ( result >= 50 ) return 1;

	return NULL;
}
