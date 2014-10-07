#include "AI.h"
#include <algorithm>
#include <ctime>


AI::AI(GameBoard* gameBoard, GameBoard::CellState* computerPlayerPiece)
	: m_pGameBoard(gameBoard)
	, m_playPiece( *computerPlayerPiece )
{}

/// <summary>
/// When called, sets the computer player piece to X
///	</summary>
GameBoard::CellState AI::SetAIPieceX( )
{
	GameBoard::CellState playerPiece = GameBoard::CellState::X;
	return playerPiece;
}

/// <summary>
/// When called, sets the computer player piece to O
///	</summary>
GameBoard::CellState AI::SetAIPieceO( )
{
	GameBoard::CellState playerPiece = GameBoard::CellState::O;
	return playerPiece;
}

/// <summary>
/// An array is passed into the function as a parameter, an element 
/// of the array will then be randomly selected, then returned. 
/// This function was designed with the idea of it returning a random
/// index to use in selecting a cell for the computer to play in.
/// </summary>
int AI::GetRandomSelection(std::vector<int>& numArray )
{
	int count = sizeof( numArray );
	int randomIndex = rand() % count;
	return randomIndex;
}

int AI::GetRandomSelection( int& count )
{
	int randomIndex = rand() % count;
	return randomIndex;
}


/// <summary>
///	function will return a random int from 0 - 8, a
/// Very simplistic way of getting a random int value.
///	</summary>
int AI::GetRandomIndex(int& count)
{
	srand( time( NULL ) );
	int index;
	index = rand() % count;
	return index;
}

void AI::SetPlayPieceOnBoard(int& index)
{
	if ( index > -1 && 
		 index < 10 )
	{
		m_pGameBoard->SetCellState( index, m_playPiece );
	}
}


/// <summary>
/// Sets the value of the human player piece to the opposite of the computer piece
/// </summary>
void AI::SetPlayerPieces(GameBoard::CellState& computerPlayerPiece)
{
	m_playPiece = computerPlayerPiece;

	if (m_playPiece == GameBoard::CellState::O) m_HumanPiece = GameBoard::CellState::X;
	else if (m_playPiece == GameBoard::CellState::X) m_HumanPiece = GameBoard::CellState::O;
}

int AI::EvaluateGameBoard()
{
	// if any of the set of three are equal, return the index of the empty cell
	std::vector<int> set1 = { 0,1,2 };
	std::vector<int> set2 = { 3,4,5 };
	std::vector<int> set3 = { 6,7,8 };
	std::vector<int> set4 = { 0,3,6 };
	std::vector<int> set5 = { 1,4,7 };
	std::vector<int> set6 = { 2,5,8 };
	std::vector<int> set7 = { 0,4,8 };
	std::vector<int> set8 = { 2,4,6 };

	std::list<std::vector<int>> SetList = { set1,set2,set3,set4,set5,set6,set7,set8 };

	for ( std::list<std::vector<int>>::const_iterator lItr = SetList.begin(); lItr != SetList.end(); ++lItr )
	{
		// now check for a winning move
		int nonEmptyCounter = 0;
		for ( std::vector<int>::const_iterator itr = lItr->begin( ); itr != lItr->end( ); ++itr )
		{
			// if any two are equal, return index to the empty cell			
			if ( m_pGameBoard->GetCellState( *itr ) == m_HumanPiece ) nonEmptyCounter++;

			// If we found two matching in the winning row, return the Empty cell index to stop winning move
			if ( nonEmptyCounter >= 2 )
			{
				for ( std::vector<int>::const_iterator itr = lItr->begin( ); itr != lItr->end( ); ++itr )
				{
					if ( m_pGameBoard->GetCellState( *itr ) == GameBoard::EMPTY ) return *itr;
				}
			}
		}
	}
	return -1;
}

/// <summary>
/// Evaluate the board for a position which could allow the computer
/// to perform a winning move
/// </summary>
int AI::PlayAdjacentCellPosition()
{
	std::vector<int> set1 = { 0, 1, 2 };
	std::vector<int> set2 = { 3, 4, 5 };
	std::vector<int> set3 = { 6, 7, 8 };
	std::vector<int> set4 = { 0, 3, 6 };
	std::vector<int> set5 = { 1, 4, 7 };
	std::vector<int> set6 = { 2, 5, 8 };
	std::vector<int> set7 = { 0, 4, 8 };
	std::vector<int> set8 = { 2, 4, 6 };

	std::list<std::vector<int>> SetList = { set1, set2, set3, set4, set5, set6, set7, set8 };

	// if we have a piece in one of these position, and an adjacent position is not blocked
	// we want to place a piece to try to win.
	for ( std::list<std::vector<int>>::const_iterator lItr = SetList.begin( ); lItr != SetList.end( ); ++lItr )
	{
		// now check for a winning move
		int nonEmptyCounter = 0;
		for ( std::vector<int>::const_iterator itr = lItr->begin( ); itr != lItr->end( ); ++itr )
		{
			// if any two are equal, return index to the empty cell
			if ( m_pGameBoard->GetCellState( *itr ) == m_playPiece ) nonEmptyCounter++;

			// If we found two matching in the winning row, return the Empty cell index to attempt a winning move
			if ( nonEmptyCounter >= 2 )
			{
				for ( std::vector<int>::const_iterator itr = lItr->begin( ); itr != lItr->end( ); ++itr )
				{
					if (m_pGameBoard->GetCellState(*itr) == m_HumanPiece) break;
					else if ( m_pGameBoard->GetCellState( *itr ) == GameBoard::EMPTY ) return *itr;
				}
			}
		}
	}
	return -1;
}

/// <summary>
/// Evaluate the board after player 1 goes and determine a first position
/// </summary>
int AI::PlayBestPositions()
{
	int count = NULL;
	int i = 0x00;
	int boardCellIndex = NULL;

	std::vector<int> startingPositions = { 2,4,6,8,0 };
	for ( std::vector<int>::iterator itr = startingPositions.begin(); itr != startingPositions.end(); ++itr )
	{
		if ( m_pGameBoard->GetCellState( *itr ) == GameBoard::EMPTY ) count++;
	}

	if ( count != NULL )
	{
		boardCellIndex = GetRandomIndex( count );
		return boardCellIndex;
	}
	else
	{
		return boardCellIndex;
	}
	
	return -1;
}

/// <summary>
/// Function will perform determination on which cell to place
/// the computer player piece on. Computer player piece is O.
///</summary>
void AI::GetAIPlayCell(GameBoard::CellState& computerPlayerPiece)
{
	Sleep( 500 );

	if (m_playPiece != GameBoard::O ||
		m_playPiece != GameBoard::X )
	{
		SetPlayerPieces(computerPlayerPiece);
	}

	int AICellDecision = NULL;

	// going to replace this logic with something more smart
	AICellDecision = PlayAdjacentCellPosition();
	if ( AICellDecision == -1 )
	{
		AICellDecision = EvaluateGameBoard();
		if ( AICellDecision == -1 )
		{
			AICellDecision = PlayBestPositions();
		}
	}

	if ( m_pGameBoard->GetCellState( AICellDecision ) == m_pGameBoard->EMPTY )
	{
		SetPlayPieceOnBoard( AICellDecision );
	}
	else if ( m_pGameBoard->GetCellState( AICellDecision ) != m_pGameBoard->EMPTY )
	{
		std::vector<int> gameCells = { 0,1,2,3,4,5,6,7,8 };
		std::vector<int>::iterator itr = gameCells.begin();
		for ( ; itr != gameCells.end(); ++itr )
		{
			//AICellDecision = PlayBestPositions( );
			if ( m_pGameBoard->GetCellState( *itr ) == GameBoard::EMPTY ) { SetPlayPieceOnBoard( *itr ); break; }
		}
	}
}


